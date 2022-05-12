#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    while (n != 0)
    {
        if (n & 1)
        {
            if (n == 1) // if a number is power of 2, there will be only one 1 in its binary value. Ex- 8 => 1000
            {
                return true;
            }
            break;
        }
        n = n >> 1;
    }
    return false;
}

int main()
{
    int n, complement = 0;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}