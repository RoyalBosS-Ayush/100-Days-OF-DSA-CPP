#include <iostream>

using namespace std;

void selectionSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int minIndex = start;
        for (int j = start + 1; j < end; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[start], arr[minIndex]);
        selectionSort(arr, start + 1, end);
    }
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    selectionSort(arr, 0, 5);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}