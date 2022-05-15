#include <iostream>

using namespace std;

void sort012(int *arr, int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j < n - i; j++)
    //     {
    //         if (arr[j - 1] > arr[j])
    //         {
    //             swap(arr[j - 1], arr[j]);
    //         }
    //     }
    // }

    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }

    for (int i = count0; i < (count0 + count1); i++)
    {
        arr[i] = 1;
    }

    for (int i = (count0 + count1); i < n; i++)
    {
        arr[i] = 2;
    }
}

int main()
{

    int arr[6] = {0, 1, 2, 2, 1, 0};

    sort012(arr, 6);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}