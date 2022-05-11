#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    //    1
    //   121
    //  12321
    // 1234321

    int n, i = 1, j, k;
    cout << "Enter a number: ";
    cin >> n;

    while (i <= n)
    {

        j = 1;
        while (i + j <= n)
        {
            cout << " ";
            j++;
        }

        k = 1;
        while (j + k - 1 < n)
        {
            cout << k;
            k++;
        }

        while (k > 0)
        {
            cout << k;
            k--;
        }

        cout << endl;
        i++;
    }

    return 0;
}