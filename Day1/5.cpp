#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // A B C
    // A B C
    // A B C

    int n, i = 0, j;
    cout << "Enter a number: ";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            char ch = 'A' + j;
            cout << ch << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}