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

// hierarchical inheritance
class Bike : public Vehicle
{
public:
    Bike()
    {
        cout << "Bike Constructor" << endl;
    }
};

int main()
{
    Car SUV;
    Bike Splendor;

    return 0;
}