#include <iostream>

using namespace std;

int main()
{
    // evil program
    while (true)
    {
        int *ptr = new int;
    }
    return 0;
}