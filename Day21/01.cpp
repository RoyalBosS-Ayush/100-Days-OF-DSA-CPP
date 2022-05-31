#include <iostream>

using namespace std;

class Vehicle
{
public:
    bool ev;
    int no_of_wheels;

    void set_ev(bool isEv)
    {
        this->ev = isEv;
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        this->no_of_wheels = 4;
    }
};

int main()
{
    Car SUV;
    SUV.set_ev(true);

    cout << "No of wheels in car SUV = " << SUV.no_of_wheels << endl;
    cout << "Is EV? " << SUV.ev << endl;

    return 0;
}