#include <iostream>

using namespace std;

class Student
{

public:
    int roll_no;
};

int main()
{
    // static  allocation
    Student obj;
    obj.roll_no = 1;
    cout << "obj.roll_no = " << obj.roll_no << endl;

    // dynamic  allocation
    Student *obj2 = new Student;
    obj2->roll_no = 2; // (*obj2).roll_no
    cout << "(*obj2).roll_no = obj2->roll_no = " << obj2->roll_no << endl;

    return 0;
}