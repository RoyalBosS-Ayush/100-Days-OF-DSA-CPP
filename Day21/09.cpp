#include <iostream>

using namespace std;

class SideCar
{
public:
    SideCar()
    {
        cout << "SideCar Constructor" << endl;
    }
};

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

// hybrid inheritance
class Bike : public Vehicle, public SideCar
{
public:
    Bike()
    {
        cout << "Bike Constructor" << endl;
    }
};

int main()
{
    Bike Splendor;

    return 0;
}