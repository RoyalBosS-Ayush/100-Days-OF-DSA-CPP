#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[5] = {11, 12, 13, 14, 15};

    cout << "Address of first element = " << arr << endl;
    cout << "Address of first element = " << &arr << endl;
    cout << "Address of first element = " << &arr[0] << endl;
    cout << "Value of first element = " << *arr << endl;
    cout << "Value of second element = " << *(arr + 1) << endl;

    cout << "arr[2] = " << arr[2] << " = " << *(arr + 2) << endl;  // arr[i] = *(arr + i)
    cout << "2[arr] = " << 2 [arr] << " = " << *(2 + arr) << endl; // i[arr] = *(i + arr)

    // error
    // arr = arr + 1;

    int *ptr = &arr[0];
    cout << "Before: " << *ptr << endl;
    ptr = ptr + 1;
    cout << "After: " << *ptr << endl;

    return 0;
}