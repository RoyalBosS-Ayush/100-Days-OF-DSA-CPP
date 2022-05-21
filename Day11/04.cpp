#include <iostream>
#include <vector>

using namespace std;

int fastPower(int x, int n)
{
    int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            ans *= x;
        }
        x *= x;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    cout << fastPower(4, 3) << endl;  //
    cout << fastPower(2, 10) << endl; //

    return 0;
}