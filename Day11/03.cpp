#include <iostream>
#include <vector>

using namespace std;

int calc_gcd(int x, int y)
{
    while (x % y > 0)
    {
        int temp = x;
        x = x % y;
        y = temp;
    }
    return y;
}

int calc_lcm(int x, int y, int gcd)
{
    return x * y / gcd;
}

int main()
{
    int x = 12, y = 8;
    int gcd = calc_gcd(x, y);
    int lcm = calc_lcm(x, y, gcd);

    cout << "GCD = " << gcd << " LCM = " << lcm << endl;

    return 0;
}
