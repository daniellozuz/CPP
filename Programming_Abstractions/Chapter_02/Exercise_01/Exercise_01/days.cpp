#include <iostream>

using namespace std;

enum weekday_t { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

weekday_t next_day(weekday_t today);
weekday_t previous_day(weekday_t today);
weekday_t increment_day(weekday_t today, int delta);

int main(void) {
    weekday_t today = Saturday;
    cout << today << " expected: 5" << endl;
    today = next_day(today);
    cout << today << " expected: 6" << endl;
    today = next_day(today);
    cout << today << " expected: 0" << endl;
    today = previous_day(today);
    cout << today << " expected: 6" << endl;
    today = increment_day(today, 8);
    cout << today << " expected: 0" << endl;
    today = increment_day(today, 0);
    cout << today << " expected: 0" << endl;
    today = increment_day(today, -2);
    cout << today << " expected: 5" << endl;

    cin.get();
    return 0;
}

weekday_t next_day(weekday_t today) {
    return weekday_t((today + 1) % 7);
}

weekday_t previous_day(weekday_t today) {
    return weekday_t((today + 6) % 7);
}

weekday_t increment_day(weekday_t today, int delta) {
    if (delta >= 0)
        return weekday_t((today + delta) % 7);
    return weekday_t((today - 6 * delta) % 7);
}
