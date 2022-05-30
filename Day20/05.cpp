#include <iostream>

using namespace std;

class Student
{
    int registration_no;

public:
    void set_registration_no(int registration_no)
    {
        this->registration_no = registration_no; // "this" is a pointer to current object
    }

    int get_registration_no()
    {
        return registration_no;
    }
};

int main()
{
    Student obj;
    cout << "Size of object = " << sizeof(obj) << endl;

    obj.set_registration_no(101);
    cout << "obj.registration_no = " << obj.get_registration_no() << endl;

    return 0;
}