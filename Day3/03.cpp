#include <iostream>

using namespace std;

int main()
{
    int cash, Rs100, Rs50, Rs20, Rs1;
    cout << "Enter cash: ";
    cin >> cash;

    switch (1)
    {
    case 1:
        Rs100 = cash / 100;
        if (Rs100)
        {
            cout << "No of 100 Rupee notes required:" << Rs100 << endl;
            cash %= 100;
        }
    case 2:
        Rs50 = cash / 50;
        if (Rs50)
        {
            cout << "No of 50 Rupee notes required:" << Rs50 << endl;
            Rs100 %= 50;
        }
    case 3:
        Rs20 = cash / 20;
        if (Rs20)
        {
            cout << "No of 20 Rupee notes required:" << Rs20 << endl;
            cash %= 20;
        }
    case 4:
        Rs1 = cash / 1;
        if (Rs1)
        {
            cout << "No of 1 Rupee notes required:" << Rs1 << endl;
        }
        break;
    default:
        cout << "Default";
    }

    return 0;
}
