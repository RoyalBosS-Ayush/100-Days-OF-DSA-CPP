#include <iostream>

using namespace std;

int main()
{

    int a, b = 1;
    a = 10;

    if (++a)       // ++a-- = 11, a = 11, condition is true
        cout << b; // 1
    else
        cout << ++b;

    return 0;
}