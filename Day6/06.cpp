#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
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

    bubbleSort(arr, N);
    cout << "After Sorting" << endl;
    print_arr(arr);

    return 0;
}

// Stable algorithm
// In place sort as it does not use additional space

// https://www.codingninjas.com/codestudio/problems/bubble-sort_980524

// https://www.geeksforgeeks.org/quiz-bubblesort-gq/