#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int b = a++; // a++ = 1, a = 2 => b = 1
    int c = ++a; // ++a = 3, a = 3 => c = 3
    cout << b;   // 1
    cout << c;   // 3
    return 0;
}