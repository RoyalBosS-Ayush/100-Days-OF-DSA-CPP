#include <iostream>

using namespace std;

int main()
{
    int n = 1;
    switch (n)
    {
    case 1:
        cout << "Inside switch" << endl;
        continue; // error: continue statement not within a loop
    default:
        cout << "Default" << endl;
        break;
    }
    return 0;
}