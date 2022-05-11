#include <iostream>

using namespace std;

int main()
{
    // cpp program to print Lowercase for (a-z), Uppercase for (A-Z), Numeric for (0-9)

    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 97 && ch <= 122)
    {
        cout << "Lowercase";
    }
    else if (ch >= 65 && ch <= 90)
    {
        cout << "Uppercase";
    }
    else if (ch >= 48 && ch <= 57)
    {
        cout << "Numeric";
    }
    return 0;
}