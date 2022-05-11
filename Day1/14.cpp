#include <iostream>

using namespace std;

int main()
{
    // cpp program to print pattern
    //    1
    //   22
    //  333
    // 4444

    int n, i = 1, j;
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