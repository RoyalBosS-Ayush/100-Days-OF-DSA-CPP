#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10

    int n, i = 0, j = 0, k = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << ++k << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}