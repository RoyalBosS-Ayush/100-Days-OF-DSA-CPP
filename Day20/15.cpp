#include <iostream>

using namespace std;

class Hero
{
public:
    string name = "Rajni";

    // void set_name(string str) // error
    // {
    //     cout << "Function Called" << endl;
    //     this->name = str;
    // }

    void set_name2(string str) const // constant member function
    {
        cout << "Constant Member Function Called" << endl;
        // this->name = str; // error
    }
};

// constant object example
int main()
{
    const Hero Rajni;

    // Rajni.name = "RAJNI"; // error
    // Rajni.set_name("RAJNI"); // error
    cout << "Rajni.name = " << Rajni.name << endl;

    Rajni.set_name2("RAJNI2");
    cout << "Rajni.name = " << Rajni.name << endl;

    return 0;
}