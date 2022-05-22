#include <iostream>
#include <vector>

using namespace std;

void update(int *p)
{
    *p += 1;
    p += 1;
}

int main()
{
    int value = 5;
    int *p = &value;

    cout << "Before: p= " << p << " *p= " << *p << endl;
    update(p);
    cout << "After: p= " << p << " *p= " << *p << endl;

    return 0;
}