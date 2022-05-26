#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int *input, int key, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + (end - start) / 2);
    if (input[mid] == key)
    {
        return mid;
    }
    else if (input[mid] > key)
    {
        return binarySearch(input, key, start, mid - 1);
    }
    else
    {
        return binarySearch(input, key, mid + 1, end);
    }
}

int binarySearch(int *input, int n, int val)
{
    return binarySearch(input, val, 0, n);
}

int main()
{
    int size = 7;
    int key = 3;
    int arr[] = {1, 3, 7, 9, 11, 12, 45};

    cout << binarySearch(arr, size, key) << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/binary-search_972