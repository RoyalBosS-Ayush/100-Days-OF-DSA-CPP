#include <iostream>

using namespace std;

void BubbleSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    BubbleSort(arr, n - 1);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    BubbleSort(arr, 5);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}