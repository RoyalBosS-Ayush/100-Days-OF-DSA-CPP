#include <iostream>
#include <vector>

using namespace std;

int modularFactorial(int x, int m)
{
    cout<<m<<endl;
    long long int ans = 1;

    while (x > 0)
    {
        ans = (ans * x) % m;
        x--;
    }
    return ans;
}

int main()
{
    int x = 212, m = 1000000007;
    cout << modularFactorial(x, m) << endl; //
    cout << modularFactorial(5, 11) << endl; // 120 % 11 = 10

    return 0;
}
