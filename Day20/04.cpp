#include <iostream>

using namespace std;

class Student
{
    int registration_no;
    char ch;
};

int main()
{
    Student obj;
    cout << "Size of object = " << sizeof(obj) << endl; // 8

    return 0;
}