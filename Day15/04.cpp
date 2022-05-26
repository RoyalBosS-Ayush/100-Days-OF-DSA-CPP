#include <iostream>

using namespace std;

int sum(int arr[], int size)
{
    if (size>=0)
    {
        return arr[size] + sum(arr, size-1); // 6 + 1 + 5 + 2 + 3 = 17
    }
    return 0;
}

int main()
{
    int size = 5;
    int arr[] = {3, 2, 5, 1, 6};

    cout << "Sum = " << sum(arr, size - 1) << endl;

    return 0;
}