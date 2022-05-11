#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // A B C
    // D E F
    // G H I

    int n, i = 0, j, k = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            char ch = 'A' + k;
            cout << ch << " ";
            k++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}