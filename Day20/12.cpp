#include <iostream>

using namespace std;

class Hero
{
public:
    int health;

    Hero()
    {
        cout << "Contructor called" << endl;
    }

    ~Hero()
    {
        cout << "Destructor Called" << endl;
    }
};

// Destructor example
int main()
{
    Hero Rajni; // static allocation
    Rajni.health = 80;

    cout << "Rajni.health = " << Rajni.health << endl;

    Hero *Shaktimaan = new Hero; // dynamic allocation
    Shaktimaan->health = 50;
    cout << "Shaktimaan.health = " << Shaktimaan->health << endl;

    delete Shaktimaan;

    return 0;
}