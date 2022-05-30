#include <iostream>

using namespace std;

class Student
{
    int roll_no;
    int reg_no;

public:
    void set_roll_no(int roll)
    {
        this->roll_no = roll;
    }
    int get_roll_no()
    {
        return this->roll_no;
    }
    void set_reg_no(int reg);
    int get_reg_no();
};

void Student::set_reg_no(int reg)
{
    this->reg_no = reg;
}

int Student::get_reg_no()
{
    return this->reg_no;
}

// member function defined inside & outside the class
int main()
{
    Student s1;

    s1.set_reg_no(101);
    s1.set_roll_no(1);

    cout << "s1.reg_no = " << s1.get_reg_no() << endl;
    cout << "s1.roll_no = " << s1.get_roll_no() << endl;

    return 0;
}