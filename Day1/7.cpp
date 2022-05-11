#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // A B C
    // B C D
    // C D E

    int n, i = 0, j;
    cout << "Enter a number: ";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            char ch = 'A' + i + j;
            cout << ch << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}