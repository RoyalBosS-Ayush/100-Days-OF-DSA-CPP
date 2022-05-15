#include <iostream>
#include <vector>

using namespace std;

int getPivot(vector<int> &arr, int n)
{
    int start = 0, end = n - 1, mid;

    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}

int binarySearch(vector<int> &arr, int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main()
{
    vector<int> arr = {2, 4, 5, 6, 8, 9, 1};

    cout << findPosition(arr, 7, 2);

    return 0;
}