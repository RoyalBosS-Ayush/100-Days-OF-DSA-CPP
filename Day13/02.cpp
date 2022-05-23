#include <iostream>

using namespace std;

int main()
{
    int a = 7;
    int &b = a;

    cout << "Before a = " << a << ", b = " << b << endl;
    b++;
    cout << "After a = " << a << ", b = " << b << endl;

    return 0;
}