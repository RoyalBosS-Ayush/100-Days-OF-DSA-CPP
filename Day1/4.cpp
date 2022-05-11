#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // 1
    // 2 3
    // 3 4 5
    // 4 5 6 7
    // 5 6 7 8 9

    int n, i = 0, j;
    cout << "Enter a number";
    cin >> n;

    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << ++j + i << " ";
        }
        cout << endl;
        i++;
    }

    return 0;
}