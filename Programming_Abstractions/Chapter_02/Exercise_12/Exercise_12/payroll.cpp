#include <iostream>
#include <string>

using namespace std;

struct employee_t {
    string name;
    string title;
    string ssnum;
    double salary;
    int withholding;
};

struct payroll_t {
    int number_of_employees;
    employee_t *employees;
};

payroll_t *get_payroll(int number_of_employees);
void show_payroll(payroll_t *payroll, int number_of_employees);

int main(void) {
    int number_of_employees;

    cout << "How many employees: ";
    cin >> number_of_employees;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    payroll_t *the_payroll = get_payroll(number_of_employees);
    show_payroll(the_payroll, number_of_employees);

    cin.get();
    return 0;
}

payroll_t *get_payroll(int number_of_employees) {
    payroll_t *payroll = new payroll_t;
    payroll->employees = new employee_t[number_of_employees];
    for (int i = 0; i < number_of_employees; i++) {
        cout << "Employee #" << i + 1 << endl;
        cout << "\t Name: ";
        getline(cin, payroll->employees[i].name);
        cout << "\t Title: ";
        getline(cin, payroll->employees[i].title);
        cout << "\t SSNum: ";
        getline(cin, payroll->employees[i].ssnum);
        cout << "\t Salary: ";
        cin >> payroll->employees[i].salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t Withholding exemptions: ";
        cin >> payroll->employees[i].withholding;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return payroll;
}

void show_payroll(payroll_t *payroll, int number_of_employees) {
    cout << "The payroll:" << endl;
    for (int i = 0; i < number_of_employees; i++) {
        cout << "Employee #" << i + 1 << endl;
        cout << "\t Name: " << payroll->employees[i].name << endl;
        cout << "\t Title: " << payroll->employees[i].title << endl;
        cout << "\t SSNum: " << payroll->employees[i].ssnum << endl;
        cout << "\t Salary: " << payroll->employees[i].salary << endl;
        cout << "\t Withholding exemptions: " << payroll->employees[i].withholding << endl;
    }
}
