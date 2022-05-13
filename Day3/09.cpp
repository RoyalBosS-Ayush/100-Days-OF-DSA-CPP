#include <iostream>

using namespace std;

int update(int a)
{
    int ans = a * a;
    return ans;
}

int main()
{
    int a = 14;
    a = update(a);

    cout << a << endl; // 196 (14*14)

    return 0;
}