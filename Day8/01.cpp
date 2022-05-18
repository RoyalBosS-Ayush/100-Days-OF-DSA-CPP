#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    int start = m + 1;
    int end = arr.size() - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int m = 3;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    reverseArray(arr, m);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298