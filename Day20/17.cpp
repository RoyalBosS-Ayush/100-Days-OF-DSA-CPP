#include <iostream>

using namespace std;

class Student
{
public:
    static int count;
    Student()
    {
        count++;
    }

    ~Student()
    {
        count--;
    }
};

int Student::count = 0;

// Static Data Member example
int main()
{
    Student s1, s2, s3;

    cout << "Total Students = " << s1.count << endl;
    cout << "s1.count = " << s1.count << endl;
    cout << "s2.count = " << s2.count << endl;
    cout << "s3.count = " << s3.count << endl;

    return 0;
}