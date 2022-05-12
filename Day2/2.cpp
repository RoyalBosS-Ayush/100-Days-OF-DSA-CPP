#include <iostream>

using namespace std;

int main()
{

    int a = 1;
    int b = 2;

    if (a-- > 0 && ++b > 2) // a-- = 1, a = 0, ++b = 3, b = 3, condition is true
    {
        cout << "Stage1 - Inside If ";
    }
    else
    {
        cout << "Stage2 - Inside Else ";
    }

    cout << a << " " << b << endl; // 0 3
    return 0;
}