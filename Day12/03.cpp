#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[5] = {11, 12, 13, 14, 15};
    char ch[10] = "RoyalBosS";
    char *ptr = &ch[0];

    cout << "arr = " << arr << endl;
    cout << "ch = " << ch << endl;
    cout << "ptr = " << ptr << endl;

    char ch2 = 'r';
    char *ptr2 = &ch2;
    cout << "ch2 = " << ch2 << endl;
    cout << "ptr2 = " << ptr2 << endl;

    return 0;
}