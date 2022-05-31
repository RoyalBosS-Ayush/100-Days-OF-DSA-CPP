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

    void Say(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << endl;
        }
    }

    void Say(string s, int n = 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s << endl;
        }
    }
};

// Function Overloading Example
int main()
{
    Hero Rajni;

    Rajni.Say();
    Rajni.Say(3);
    // Rajni.Say("Hi RoyalBosS"); // error
    Rajni.Say("Hi RoyalBosS", 2);

    return 0;
}