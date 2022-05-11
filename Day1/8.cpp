#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // A
    // B B
    // C C C
    // D D D D

    int n, i = 0, j;
    cout << "Enter a number: ";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            char ch = 'A' + i;
            cout << ch << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}