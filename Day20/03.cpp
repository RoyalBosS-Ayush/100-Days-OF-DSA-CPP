#include <iostream>

using namespace std;

class Student
{
    int registration_no;

protected:
    int std;

public:
    int roll_no;
};

int main()
{
    Student obj;
    cout << "Size of object = " << sizeof(obj) << endl;

    // Error - Cannot access private data member outside class
    // obj.registration_no = 101;
    // cout << "obj.roll_no = " << obj.registration_no << endl;

    // Error - Cannot access protected data member outside class
    // obj.std = 12;
    // cout << "obj.roll_no = " << obj.std << endl;

    obj.roll_no = 10;
    cout << "obj.roll_no = " << obj.roll_no << endl;

    return 0;
}