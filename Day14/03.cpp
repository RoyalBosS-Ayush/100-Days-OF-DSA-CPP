#include <iostream>

using namespace std;

#define PI 3.1428

float radius;

inline double area(float r = 0)
{
    return PI * r * r;
}

int main()
{
    radius = 5;
    cout << "Area of circle having radius " << radius << " is " << area(radius) << endl;
    return 0;
}