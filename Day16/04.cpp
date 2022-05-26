#include <iostream>

using namespace std;

int pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int ans = pow(a, b / 2);
    if (b & 1)
    {
        return ans * ans * 2;
    }
    else
    {
        return ans * ans;
    }
}

int main()
{
    int a, b;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Raised to the power? ";
    cin >> b;

    cout << pow(a, b);
    return 0;
}