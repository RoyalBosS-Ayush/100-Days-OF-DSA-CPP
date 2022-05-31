#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "Vehicle Constructor" << endl;
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        cout << "Car Constructor" << endl;
    }
};

// multi-level inheritance
class Tesla : public Car
{
public:
    Tesla()
    {
        cout << "Tesla Constructor" << endl;
    }
};

int main()
{
    Tesla ModelX;

    return 0;
}