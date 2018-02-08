#include <iostream>
#include <vector>

using namespace std;

const int WINNING_POSITION = 1000;
const int NEUTRAL_POSITION = 0;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 10000;
const int N_PILES = 3;
const int N_COINS[N_PILES] = { 3, 4, 5 };
const int NO_GOOD_MOVE = -1;

enum player_t { Human, Computer };
const player_t FIRST_PLAYER = Computer;

struct move_t {
	int pile;
	int coins;
};

struct state_t {
	player_t whose_turn;
	int coins_left[N_PILES];
};

void give_instructions();
move_t find_best_move(state_t state, int depth, int &rating);
int evaluate_position(state_t state, int depth);
state_t new_game();
void display_game(state_t state);
void display_move(move_t move);
move_t get_user_move(state_t state);
move_t choose_computer_move(state_t state);
void generate_move_list(state_t state, vector<move_t> &move_list);
bool move_is_legal(move_t move, state_t state);
void make_move(state_t &state, move_t move);
void retract_move(state_t &state, move_t move);
bool game_is_over(state_t state);
void announce_result(state_t state);
player_t whose_turn(state_t state);
player_t opponent(player_t player);
int evaluate_static_position(state_t state);
bool check_for_win(state_t state, player_t player);
int get_integer(void);
move_t get_move(void);

int main() {
	give_instructions();
	state_t state = new_game();
	move_t move;
	while (!game_is_over(state)) {
		display_game(state);
		switch (whose_turn(state)) {
		case Human:
			move = get_user_move(state);
			break;
		case Computer:
			move = choose_computer_move(state);
			display_move(move);
			break;
		}
		make_move(state, move);
	}
	announce_result(state);

	cin.get();
	return 0;
}

void give_instructions() {
	cout << "Hello. Welcome to the game of nim." << endl;
	cout << "In this game, we will start with three piles of coins on the table." << endl;
	cout << "On each turn, you and I will alternately take any number of coins from one of the piles." << endl;
	cout << "The player who takes the last coin loses." << endl << endl;
}

void display_game(state_t state) {
	cout << "There are ";
	for (int i = 0; i < N_PILES-1; i++)
		cout << state.coins_left[i] << ", ";
	cout << state.coins_left[N_PILES - 1] << " coins left." << endl;
}

move_t find_best_move(state_t state, int depth, int &rating) {
	vector<move_t> move_list;
	move_t best_move;
	generate_move_list(state, move_list);
	int n_moves = move_list.size();
	if (n_moves == 0)
		cout << "Error! No moves available";
	int min_rating = WINNING_POSITION + 1;
	for (int i = 0; i < n_moves && min_rating != LOSING_POSITION; i++) {
		move_t move = move_list[i];
		make_move(state, move);
		int cur_rating = evaluate_position(state, depth + 1);
		if (cur_rating < min_rating) {
			best_move = move;
			min_rating = cur_rating;
		}
		retract_move(state, move);
	}
	rating = -min_rating;
	return best_move;
}

int evaluate_position(state_t state, int depth) {
	int rating;
	if (game_is_over(state) || depth >= MAX_DEPTH)
		return evaluate_static_position(state);
	find_best_move(state, depth, rating);
	return rating;
}

state_t new_game() {
	state_t state;
	for (int i = 0; i < N_PILES; i++)
		state.coins_left[i] = N_COINS[i];
	state.whose_turn = FIRST_PLAYER;
	return state;
}

void display_move(move_t move) {
	cout << "I'll take " << move.coins << " coins from " << move.pile << " pile." << endl;
}

move_t get_user_move(state_t state) {
	cout << "Your move." << endl;
	move_t move;
	while (true) {
		move = get_move();
		if (move_is_legal(move, state))
			break;
		cout << "That move is illegal. Try again." << endl;
	}
	return move;
}

move_t get_move(void) {
	move_t move;
	cout << "Which pile? ";
	move.pile = get_integer() - 1;
	cout << "How many coins? ";
	move.coins = get_integer();
	return move;
}

move_t choose_computer_move(state_t state) {
	int rating;
	cout << "My move." << endl;
	return find_best_move(state, 0, rating);
}

void generate_move_list(state_t state, vector<move_t> &move_list) {
	for (int p = 0; p < N_PILES; p++) {
		for (int i = 1; i <= state.coins_left[p]; i++) {
			move_t move = { p, i };
			if (move_is_legal(move, state))
				move_list.push_back(move);
		}
	}
}

bool move_is_legal(move_t move, state_t state) {
	return (move.coins <= state.coins_left[move.pile] && move.coins > 0);
}

void make_move(state_t &state, move_t move) {
	state.coins_left[move.pile] -= move.coins;
	state.whose_turn = opponent(state.whose_turn);
}

void retract_move(state_t & state, move_t move) {
	state.coins_left[move.pile] += move.coins;
	state.whose_turn = opponent(state.whose_turn);
}

bool game_is_over(state_t state) {
	for (int i = 0; i < N_PILES; i++) {
		if (state.coins_left[i] != 0)
			return false;
	}
	return true;
}

void announce_result(state_t state) {
	display_game(state);
	if (check_for_win(state, Human))
		cout << "You win." << endl;
	else
		cout << "I win." << endl;
}

player_t whose_turn(state_t state) {
	return state.whose_turn;
}

player_t opponent(player_t player) {
	return (player == Human) ? Computer : Human;
}

int evaluate_static_position(state_t state) {
	if (check_for_win(state, state.whose_turn))
		return WINNING_POSITION;
	if (check_for_win(state, opponent(state.whose_turn)))
		return LOSING_POSITION;
	return NEUTRAL_POSITION;
}

bool check_for_win(state_t state, player_t player) {
	return state.whose_turn == player;
}

int get_integer(void) {
	int integer;
	cin >> integer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return integer;
}
