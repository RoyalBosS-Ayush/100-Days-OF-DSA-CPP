#include <iostream>

using namespace std;

class Hero
{
public:
    void Say(string s)
    {
        cout << s << endl;
    }
};

class Rajni : public Hero
{
public:
    void Say(string s)
    {
        cout << "Rajni: " << s << endl;
    }
};

// Function Overriding
int main()
{
    Rajni Rajinikanth;

    Rajinikanth.Say("Hi");
    Rajinikanth.Hero::Say("Hi");
    Rajinikanth.Rajni::Say("Hi");

    return 0;
}