#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // binary to decimal
    int binary, decimal;
    cout << "Enter Binary Number: ";
    cin >> binary;

    for (int i = 0; binary > 0; i++, binary /= 10)
    {
        if (binary & 1)
        {
            decimal += pow(2, i);
        }
    }

    cout << "Decimal Value = " << decimal;

    return 0;
}