#include <iostream>

using namespace std;

int main()
{
    int a, b, pow = 1;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Raised to the power? ";
    cin >> b;

    for (int i = 0; i < b; i++)
    {
        pow *= a;
    }

    cout << a << " raised to power " << b << " is " << pow;

    return 0;
}