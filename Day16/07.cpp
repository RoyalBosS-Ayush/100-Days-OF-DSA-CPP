#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int *arr, int i, int n)
{
    if (i < n)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;

        insertionSort(arr, i + 1, n);
    }
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    insertionSort(arr, 1, 5);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}