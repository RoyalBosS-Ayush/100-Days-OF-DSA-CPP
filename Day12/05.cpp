#include <iostream>
#include <vector>

using namespace std;

void func(int arr[])
{
    cout << "Size of arr in func = " << sizeof(arr) << endl;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    func(arr);

    return 0;
}