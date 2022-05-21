#include <iostream>
#include <vector>

using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            ans = (1ll * ans * x) % m;
        }
        x = (1ll * x * x) % m;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int x = 4, n = 3, m = 10;
    cout << modularExponentiation(x, n, m) << endl; //

    return 0;
}

// (X ^ N) % M

// n        ans x
// 3(11)    4   6
// 1(01)    4   6