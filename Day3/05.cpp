#include <iostream>

using namespace std;

int countSetBits(int a)
{
    int count = 0;
    while (a != 0)
    {
        int bit = a & 1;
        if (bit)
        {
            count++;
        }
        a = a >> 1;
    }
    return count;
}

int main()
{
    int a, b;
    cout << "Enter two space seperated number: ";
    cin >> a >> b;

    cout << "Total set bits: " << countSetBits(a) + countSetBits(b);

    return 0;
}