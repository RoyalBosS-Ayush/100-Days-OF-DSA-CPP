#include <iostream>

using namespace std;

void update(int **p)
{
    **p += 1; // change
    *p += 1;  // change
    p += 1;   // no change
}

int main()
{
    int i = 7;
    int *ptr = &i;
    int **ptr2 = &ptr;

    cout << "Before \n";

    cout << "&i = " << &i << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "&ptr = " << &ptr << endl;
    cout << "ptr2 = " << ptr2 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "**ptr2 = " << **ptr2 << endl;

    update(ptr2);

    cout << "\nAfter \n";

    cout << "&i = " << &i << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "&ptr = " << &ptr << endl;
    cout << "ptr2 = " << ptr2 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "**ptr2 = " << **ptr2 << endl;

    return 0;
}