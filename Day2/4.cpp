#include <iostream>

using namespace std;

int main()
{
    int number = 3;
    cout << (25 * (++number)); // ++number = 4, number = 4 => 25*4=100
    return 0;
}