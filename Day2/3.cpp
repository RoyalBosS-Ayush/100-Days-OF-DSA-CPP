#include <iostream>

using namespace std;

int main()
{

    int a = 1;
    int b = 2;

    if (a-- > 0 || ++b > 2) // a-- = 1, a = 0, Since first condition is true, second condition will not be checked (In OR) => b = 2
    {
        cout << "Stage1 - Inside If ";
    }
    else
    {
        cout << "Stage2 - Inside Else ";
    }

    cout << a << " " << b << endl; // 0 2
    return 0;
}