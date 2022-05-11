#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    // 1111
    //  222
    //   33
    //    4

    int n, i = 1, j;
    cout << "Enter a number: ";
    cin >> n;

    while (i <= n)
    {

        j = 1;
        while (i > j)
        {
            cout << " ";
            j++;
        }

        while (j <= n)
        {
            cout << i;
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}