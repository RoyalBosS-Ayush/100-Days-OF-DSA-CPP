#include <iostream>

using namespace std;

class Hero
{
public:
    int health;
    char *name;
};

// shallow copy example
int main()
{
    Hero Rajni;
    Rajni.health = 99;
    char RajniName[] = "RAJNI";
    Rajni.name = RajniName;

    cout << "Rajni.health = " << Rajni.health << endl;
    cout << "Rajni.name = " << Rajni.name << endl;

    Hero Shaktimaan(Rajni);
    cout << "Shaktimaan.health = " << Shaktimaan.health << endl;
    cout << "Shaktimaan.name = " << Shaktimaan.name << endl;

    cout << endl
         << "Updating Rajni's name and health" << endl;

    Rajni.health = 100;
    Rajni.name[0] = 'r';

    cout << "Rajni.health = " << Rajni.health << endl;
    cout << "Rajni.name = " << Rajni.name << endl;

    cout << "Shaktimaan.health = " << Shaktimaan.health << endl;
    cout << "Shaktimaan.name = " << Shaktimaan.name << endl;

    return 0;
}