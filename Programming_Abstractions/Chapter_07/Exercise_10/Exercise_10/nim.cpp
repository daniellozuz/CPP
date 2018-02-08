#include <iostream>
#include <vector>

using namespace std;

const int WINNING_POSITION = 1000;
const int NEUTRAL_POSITION = 0;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 10000;

enum player_t { Human, Computer };
const player_t FIRST_PLAYER = Computer;

typedef int move_t;

struct state_t {
	vector<vector<char>> board;
	player_t whose_turn;
	int turns_taken;
};

void give_instructions();
move_t find_best_move(state_t state, int depth, int &rating);
int evaluate_position(state_t state, int depth);
state_t new_game();
void display_game(state_t state);
void display_move(move_t move);
char player_mark(player_t player);
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
bool check_for_win(vector<vector<char>> &board, char mark);
bool check_line(vector<vector<char>> &board, char mark, int row, int col, int d_row, int d_col);
int get_integer(void);

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
	cout << "Welcome to tic-tac-toe. The object of the game" << endl;
	cout << "is to line up three symbols in a row," << endl;
	cout << "vertically, horizontally, or diagonally." << endl;
	cout << "You'll be " << player_mark(Human) << " and I'll be " << player_mark(Computer) << "." << endl;
}

void display_game(state_t state) {
	if (game_is_over(state))
		cout << "The final position looks like this:" << endl << endl;
	else
		cout << "The game now looks like this:" << endl << endl;
	for (int i = 0; i < 3; i++) {
		if (i != 0)
			cout << "---+---+---" << endl;
		for (int j = 0; j < 3; j++) {
			if (j != 0)
				cout << "|";
			cout << " " << state.board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

move_t find_best_move(state_t state, int depth, int &rating) {
	vector<move_t> move_list;
	generate_move_list(state, move_list);
	int n_moves = move_list.size();
	if (n_moves == 0)
		cout << "Error! No moves available";
	move_t best_move;
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
	for (int i = 0; i < 3; i++) {
		vector<char> row;
		for (int j = 0; j < 3; j++) {
			row.push_back(' ');
		}
		state.board.push_back(row);
	}
	state.whose_turn = FIRST_PLAYER;
	state.turns_taken = 0;
	return state;
}

void display_move(move_t move) {
	cout << "I'll move to " << move << endl;
}

char player_mark(player_t player) {
	return (player == FIRST_PLAYER) ? 'X' : 'O';
}

move_t get_user_move(state_t state) {
	cout << "Your move." << endl;
	move_t move;
	while (true) {
		cout << "What square? ";
		move = get_integer();
		if (move_is_legal(move, state))
			break;
		cout << "That move is illegal. Try again." << endl;
	}
	return move;
}

move_t choose_computer_move(state_t state) {
	int rating;
	cout << "My move." << endl;
	return find_best_move(state, 0, rating);
}

void generate_move_list(state_t state, vector<move_t> &move_list) {
	for (int i = 1; i <= 9; i++) {
		move_t move = move_t(i);
		if (move_is_legal(move, state))
			move_list.push_back(move_t(i));
	}
}

bool move_is_legal(move_t move, state_t state) {
	if (move < 1 || move > 9)
		return false;
	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	return state.board[row][col] == ' ';
}

void make_move(state_t & state, move_t move) {
	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	state.board[row][col] = player_mark(state.whose_turn);
	state.whose_turn = opponent(state.whose_turn);
	state.turns_taken++;
}

void retract_move(state_t & state, move_t move) {
	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	state.board[row][col] = ' ';
	state.whose_turn = opponent(state.whose_turn);
	state.turns_taken--;
}

bool game_is_over(state_t state) {
	return (state.turns_taken == 9 || check_for_win(state, state.whose_turn) || check_for_win(state, opponent(state.whose_turn)));
}

void announce_result(state_t state) {
	display_game(state);
	if (check_for_win(state, Human))
		cout << "You win." << endl;
	else if (check_for_win(state, Computer))
		cout << "I win." << endl;
	else
		cout << "Cat's game." << endl;
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
	if (state.turns_taken < 5)
		return false;
	return check_for_win(state.board, player_mark(player));
}

bool check_for_win(vector<vector<char>> &board, char mark) {
	for (int i = 0; i < 3; i++) {
		if (check_line(board, mark, i, 0, 0, 1))
			return true;
		if (check_line(board, mark, 0, i, 1, 0))
			return true;
	}
	if (check_line(board, mark, 0, 0, 1, 1))
		return true;
	return check_line(board, mark, 2, 0, -1, 1);
}

bool check_line(vector<vector<char>> &board, char mark, int row, int col, int d_row, int d_col) {
	for (int i = 0; i < 3; i++) {
		if (board[row][col] != mark)
			return false;
		row += d_row;
		col += d_col;
	}
	return true;
}

int get_integer(void) {
	int integer;
	cin >> integer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return integer;
}
