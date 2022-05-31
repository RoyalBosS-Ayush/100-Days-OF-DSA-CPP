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

class Car
{
public:
    Car()
    {
        cout << "Car Constructor" << endl;
    }
};

// multiple inheritance
class Taxi : public Vehicle, public Car
{
public:
    Taxi()
    {
        cout << "Bike Constructor" << endl;
    }
};

int main()
{
    Taxi obj;

    return 0;
}