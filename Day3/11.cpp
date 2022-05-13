#include <iostream>

using namespace std;

int sum(int arr[], int size)
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
    int n, arr[100];
    cout << "Number of element: ";
    cin >> n;
    cout << "Enter " << n << " space seperated integers: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sum = " << sum(arr, n);

    return 0;
}