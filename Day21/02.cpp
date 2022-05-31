#include <iostream>

using namespace std;

class Vehicle
{
    bool ev;

protected:
    int seats;

public:
    int no_of_wheels;

    void set_ev(bool isEv)
    {
        this->ev = isEv;
    }

    bool isEv()
    {
        return this->ev;
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        // this->ev = false; // error
        this->seats = 4;
        this->no_of_wheels = 4;
    }

    int get_wheels()
    {
        return this->no_of_wheels;
    }
};

// public inheritance
int main()
{
    Car SUV;

    // SUV.ev = true; // error
    SUV.set_ev(true);
    // SUV.seats = 4; // error
    SUV.no_of_wheels = 4;

    cout << "Is EV? " << SUV.isEv() << endl;
    cout << "No of seat in car SUV = " << SUV.get_wheels() << endl;
    cout << "No of wheels in car SUV = " << SUV.no_of_wheels << endl;

    return 0;
}

// class car would be something like this

// {

// protected:
//     int seats;

// public:
//     int no_of_wheels;

//     void set_ev(bool isEv)
//     {
//         this->ev = isEv;
//     }

//     bool isEv()
//     {
//         return this->ev;
//     }

//     Car()
//     {
//         // this->ev = false; // error
//         this->seats = 4;
//         this->no_of_wheels = 4;
//     }

//     int get_wheels()
//     {
//         return this->no_of_wheels;
//     }
// };