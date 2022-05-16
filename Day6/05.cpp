#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr, int n)
{
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void print_arr(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int N = 5;
    vector<int> arr = {6, 2, 8, 4, 10};

    cout << "Before Sorting" << endl;
    print_arr(arr);

    selectionSort(arr, N);
    cout << "After Sorting" << endl;
    print_arr(arr);

    return 0;
}

//  Not a stable algorithm

// https://www.codingninjas.com/codestudio/problems/selection-sort_981162