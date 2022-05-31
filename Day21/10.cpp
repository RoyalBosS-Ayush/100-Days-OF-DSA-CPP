#include <iostream>

using namespace std;

class Vehicle
{
public:
    void WhoAmI()
    {
        cout << "I am Vehicle" << endl;
    }
};

class Car
{
public:
    void WhoAmI()
    {
        cout << "I am Car" << endl;
    }
};

// Ambiguity Example
class Taxi : public Vehicle, public Car
{
};

int main()
{
    Taxi obj;

    // obj.WhoAmI(); // error
    obj.Vehicle::WhoAmI();
    obj.Car::WhoAmI();

    return 0;
}