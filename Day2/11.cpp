#include <iostream>

using namespace std;

int reverse(int x)
{
    int reversed = 0;
    while (x != 0)
    {
        if ((reversed < INT32_MIN / 10) || (reversed > INT32_MAX / 10))
        {
            return 0;
        }

        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return reversed;
}

int main()
{
    // reverse integer

    int x;
    cout << "Enter a Number: ";
    cin >> x;

    cout << "Reversed Number: " << reverse(x);

    return 0;
}