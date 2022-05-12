#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // decimal to binary
    int binary, decimal;
    cout << "Enter decimal Number: ";
    cin >> decimal;

    for (int i = 0; decimal > 0; i++, decimal /= 2)
    {
        binary += pow(10, i) * (decimal % 2);
    }

    cout << "Binary Value = " << binary;

    return 0;
}