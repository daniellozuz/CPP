#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;

void read_data(float &radius, float &height);
void compute(float &radius, float &height, float &area, float &volume);
void display(float radius, float height, float area, float volume);

int main(void) {
    float radius, height, area, volume;

    read_data(radius, height);
    compute(radius, height, area, volume);
    display(radius, height, area, volume);

    cin.get();
    return 0;
}

void read_data(float &radius, float &height) {
    cout << "Cylinder radius: ";
    cin >> radius;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Cylinder height: ";
    cin >> height;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void compute(float &radius, float &height, float &area, float &volume) {
    area = 2 * M_PI * height * radius;
    volume = M_PI * height * radius * radius;
}

void display(float radius, float height, float area, float volume) {
    cout << "Cylinder dimensions:" << endl;
    cout << "Radius: " << radius << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << area << endl;
    cout << "Volume: " << volume << endl;
}
