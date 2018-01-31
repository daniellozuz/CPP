#include <iostream>

using namespace std;

void move_tower(int n, char start, char finish, char temp);
void move_disk(char start, char finish);

int main(void) {
    move_tower(3, 'A', 'B', 'C');

    cin.get();
    return 0;
}

void move_tower(int n, char start, char finish, char temp) {
    if (n != 0) {
        move_tower(n - 1, start, temp, finish);
        move_disk(start, finish);
        move_tower(n - 1, temp, finish, start);
    }
}

void move_disk(char start, char finish) {
    cout << start << " -> " << finish << endl;
}
