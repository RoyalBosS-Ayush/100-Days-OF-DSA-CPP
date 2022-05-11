#include <iostream>

using namespace std;

int main()
{
    // cpp program to print sum of all even number till given number

    int n, sum, i = 2;
    cout << "Enter a Number: ";
    cin >> n;

    while (i <= n)
    {
        sum += i;
        i += 2;
    }

    cout << "Sum of all even number till " << n << " = " << sum;

    return 0;
}