#include <iostream>

using namespace std;

class Location
{
    int x;
    int y;

public:
    Location(int i = 0, int j = 0) : x(i), y(j) // x=i y=j
    {
        cout << "Constructor Called" << endl;
    }

    void display()
    {
        cout << "x: " << this->x << " y: " << this->y << endl;
    }
};

// Initializer List example
int main()
{
    Location India(6, 9);

    India.display();

    return 0;
}