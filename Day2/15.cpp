#include <iostream>

using namespace std;

int main()
{
    int num, sqrt = 0;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (i * i > num)
        {
            break;
        }
        sqrt = i;
    }

    cout << "Sqrt of " << num << " is " << sqrt;

    return 0;
}