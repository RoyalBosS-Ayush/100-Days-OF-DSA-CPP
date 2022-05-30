#include <iostream>

using namespace std;

class Hero
{
    int health;

public:
    Hero()
    {
        this->health = 100;
    }

    Hero(int health) // constructor overloaded
    {
        this->health = health;
    }

    int get_health()
    {
        return this->health;
    }
};

int main()
{
    Hero Rajni; // Statically
    cout << "Rajni.health = " << Rajni.get_health() << endl;

    Hero Shaktimaan(80); // Statically
    cout << "Shaktimaan.health = " << Shaktimaan.get_health() << endl;

    Hero *SpiderMan = new Hero; // Dynamically
    cout << "SpiderMan->health = " << SpiderMan->get_health() << endl;

    Hero *IronMan = new Hero(50); // Dynamically
    cout << "IronMan->health = " << IronMan->get_health() << endl;

    return 0;
}