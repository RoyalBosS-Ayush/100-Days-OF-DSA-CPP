#include <iostream>

using namespace std;

class Hero
{
public:
    void Say()
    {
        cout << "Hello" << endl;
    }

    void Say(string s)
    {
        cout << s << endl;
    }
};

int main()
{
    Hero Rajni;

    Rajni.Say();
    Rajni.Say("Hi RoyalBosS");

    return 0;
}