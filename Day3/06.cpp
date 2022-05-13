#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    int prev = 0, now = 1;
    for (int i = 2; i < n; i++)
    {
        int temp = now;
        now = now + prev;
        prev = temp;
    }
    return now;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << n << "th term is " << fib(n);

    return 0;
}