#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imaginary;

public:
    Complex(int i = 0, int j = 0)
    {
        this->real = i;
        this->imaginary = j;
    }

    void display()
    {
        cout << real << " + (" << imaginary << ")j" << endl;
    }

    Complex operator+(Complex &obj)
    {
        cout << "Adding Two Complex Numbers" << endl;
        Complex ans = Complex(this->real + obj.real, this->imaginary + obj.imaginary);
        return ans;
    }

    void operator()()
    {
        cout << "Brackets!!!" << endl;
    }
};

// Function Overloading Example
int main()
{
    Complex c1 = Complex(1, 2);
    Complex c2 = Complex(2, -3);
    Complex c3 = c1 + c2;

    c3.display();
    c3();

    return 0;
}