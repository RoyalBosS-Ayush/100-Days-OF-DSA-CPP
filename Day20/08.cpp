#include <iostream>

using namespace std;

class Hero
{
    int health;

public:
    Hero(int health)
    {
        this->health = health;
    }

    Hero(Hero &h)
    {
        cout << endl << "Copy constructor called" << endl;
        this->health = h.health;
    }

    int get_health()
    {
        return this->health;
    }
};

int main()
{
    Hero Rajni(50);
    cout << "Rajni.health = " << Rajni.get_health() << endl;

    Hero Shaktimaan(Rajni);
    cout << "Shaktimaan.health = " << Shaktimaan.get_health() << endl;

    return 0;
}