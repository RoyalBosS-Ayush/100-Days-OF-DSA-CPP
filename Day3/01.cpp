#include <iostream>

using namespace std;

int main()
{
    char ch = '1';
    while (1)
    {
        switch (ch)
        {
        case '1':
            cout << "Hello!" << endl;
            exit(1);
        default:
            cout << "Default" << endl;
            break;
        }
    }
    cout << "End of while loop";
    return 0;
}