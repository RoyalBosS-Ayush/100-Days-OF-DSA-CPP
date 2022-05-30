#include <iostream>

using namespace std;

class Hero
{
public:
    const string name = "Rajni";
};

// constant data member example
int main()
{
    Hero Rajni;

    cout << "Rajni.name = " << Rajni.name << endl;

    // Rajni.name = "Rajinikanth"; // error
    // cout << "Rajni.name = " << Rajni.name << endl;

    return 0;
}