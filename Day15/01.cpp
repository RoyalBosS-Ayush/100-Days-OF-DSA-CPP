#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int prev = 0;
    int now = 1;
    for (int i = 2; i <= n; i++)
    {
        now = prev + now;
        prev = now - prev;
    }
    return now;
}

// int fib(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }
//     return fib(n - 1) + fib(n - 2);
// }

int main()
{
    int n = 7;

    cout << fib(n) << endl;

    return 0;
}

// https://leetcode.com/problems/fibonacci-number/