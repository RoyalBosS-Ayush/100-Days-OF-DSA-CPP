#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1, mid;
    while (start < end)
    {
        mid = (start + (end - start) / 2);
        if (arr[mid] < arr[mid + 1])
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

int main()
{
    vector<int> arr = {0, 10, 5, 2};

    cout << peakIndexInMountainArray(arr);

    return 0;
}