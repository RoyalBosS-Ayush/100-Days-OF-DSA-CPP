#include <iostream>

using namespace std;

class Student
{
public:
    static int count;
    int roll_no;

    Student()
    {
        count++;
    }

    ~Student()
    {
        count--;
    }

    static int countStudents()
    {
        // roll_no = 5; // error

        // can access only static data members
        // this keyword wont work here
        // can be called without object

        return count;
    }
};

int Student::count = 0;

// Static Member Function example
int main()
{
    Student s1, s2, s3;

    cout << "Total Students = " << Student::countStudents() << endl;
    cout << "Total Students = " << s1.countStudents() << endl;
    cout << "s1.count = " << s1.count << endl;
    cout << "s2.count = " << s2.count << endl;
    cout << "s3.count = " << s3.count << endl;

    return 0;
}