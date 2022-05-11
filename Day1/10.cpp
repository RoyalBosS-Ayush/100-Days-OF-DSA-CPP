#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    //    *
    //   **
    //  ***
    // ****

    int n, i = 0, j;
    cout << "Enter a number: ";
    cin >> n;

    while (i < n)
    {

        j = 0;
        while (i + j < n)
        {
            cout << " ";
            j++;
        }

        while (j <= n)
        {
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}