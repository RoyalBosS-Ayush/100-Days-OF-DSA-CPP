#include <iostream>

using namespace std;

int main()
{
    int num = 5;
    cout << "num = " << num << endl;
    cout << "address of num = " << &num << endl;

    int *ptr = &num;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "++(*ptr) = " << ++(*ptr) << endl;
    cout << "size of ptr = " << sizeof(ptr) << endl; // always 8
    cout << "size of *ptr = " << sizeof(*ptr) << endl;

    // cout << "ptr = " << ptr << endl;
    // cout << "++ptr = " << ++ptr << endl;

    int *ptr2 = 0;
    ptr2 = &num;
    cout << "ptr : " << ptr << endl;
    cout << "ptr2: " << ptr2 << endl;

    // delete ptr;
    // cout<<"num = "<<num;

    // copying a pointer
    int *ptr3 = ptr2;
    cout << "ptr2 = " << ptr2 << endl;
    cout << "ptr3 = " << ptr3 << endl;

    int a = 1;
    int *p = &a;
    int **q = &p;

    cout<<endl;
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    cout << "**q = " << **q << endl;
    cout << "sizeof(q) = " << sizeof(q) << endl;


    return 0;
}