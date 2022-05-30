#include <iostream>

using namespace std;

class Hero
{
public:
    int health;
    char *name;
};

// copy assignment operator example
int main()
{
    Hero Rajni;
    Rajni.health = 99;
    char RajniName[] = "RAJNI";
    Rajni.name = RajniName;

    cout << "Rajni.health = " << Rajni.health << endl;
    cout << "Rajni.name = " << Rajni.name << endl;

    Hero Shaktimaan = Rajni;
    cout << "Shaktimaan.health = " << Shaktimaan.health << endl;
    cout << "Shaktimaan.name = " << Shaktimaan.name << endl;

    return 0;
}