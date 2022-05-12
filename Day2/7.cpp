#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i <= 5; i--)
    {
        cout << i << " "; // i = 0 => infinite loop
        i++;
    }
    return 0;
}