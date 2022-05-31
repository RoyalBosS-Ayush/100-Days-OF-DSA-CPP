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

class Car : protected Vehicle
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

    void set_wheels(int wheels)
    {
        this->seats = wheels;
    }

    bool get_ev()
    {
        return this->isEv();
    }

    void set_ev_to(bool isEv)
    {
        this->set_ev(isEv);
    }

    int get_seats()
    {
        return this->seats;
    }

    void set_seats(int seats)
    {
        this->seats = seats;
    }
};

// protected inheritance
int main()
{
    Car SUV;

    // SUV.ev = true; // error
    // SUV.set_ev(true); // error
    SUV.set_ev_to(true);
    // SUV.seats = 4; // error
    // SUV.no_of_wheels = 4; //error

    cout << "Is EV? " << SUV.get_ev() << endl;
    cout << "No of seat in car SUV = " << SUV.get_seats() << endl;
    cout << "No of wheels in car SUV = " << SUV.get_wheels() << endl;

    return 0;
}

// class car would be something like this

// {

// protected:
//     int seats;
//     int no_of_wheels;

//     void set_ev(bool isEv)
//     {
//         this->ev = isEv;
//     }

//     bool isEv()
//     {
//         return this->ev;
//     }

// public:
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

//     void set_wheels(int wheels)
//     {
//         this->seats = wheels;
//     }

//     bool get_ev()
//     {
//         return this->isEv();
//     }

//     void set_ev_to(bool isEv)
//     {
//         this->set_ev(isEv);
//     }

//     int get_seats()
//     {
//         return this->seats;
//     }

//     void set_seats(int seats)
//     {
//         this->seats = seats;
//     }
// };