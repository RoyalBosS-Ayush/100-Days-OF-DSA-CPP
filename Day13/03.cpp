#include <iostream>

using namespace std;

int sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sum = " << sum(arr, n);

    return 0;
}