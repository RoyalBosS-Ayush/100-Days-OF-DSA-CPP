#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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

    insertionSort(N, arr);
    cout << "After Sorting" << endl;
    print_arr(arr);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179

// Adaptive algorithm because time complexity will change for partially sorted array
// Stable algorithm