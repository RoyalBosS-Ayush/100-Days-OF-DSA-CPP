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

// single inheritance
class Car : public Vehicle
{
public:
    Car()
    {
        cout << "Car Constructor" << endl;
    }
};

int main()
{
    Car SUV;

    return 0;
}