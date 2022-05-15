#include <iostream>

using namespace std;

void swap_alternate(int arr[], int size)
{
    for (int i = 1; i < size; i += 2)
    {
        swap(arr[i - 1], arr[i]);
    }
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    swap_alternate(arr, 7);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}