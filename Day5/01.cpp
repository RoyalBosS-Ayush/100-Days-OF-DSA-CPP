#include <iostream>
#include <vector>

using namespace std;

// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
// {
//     int left = 0, right = n, mid, first = -1, last = -1;
//     while (left <= right)
//     {
//         mid = (left + right) / 2;
//         if (arr[mid] == k)
//         {
//             first = last = mid;
//             while (arr[first - 1] == k && first > 0)
//             {
//                 first--;
//             }
//             while (arr[last + 1] == k && last < n - 1)
//             {
//                 last++;
//             }
//             break;
//         }
//         else if (arr[mid] > k)
//         {
//             right = mid - 1;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }
//     return pair<int, int>(first, last);
// }

int firstOcc(vector<int> arr, int n, int k)
{
    int start = 0, end = n, mid, ans = -1;
    while (start <= end)
    {
        mid = (start + (end - start) / 2);
        if (arr[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int lastOcc(vector<int> arr, int n, int k)
{
    int start = 0, end = n, mid, ans = -1;
    while (start <= end)
    {
        mid = (start + (end - start) / 2);
        if (arr[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOcc(arr, n, k);
    int last = lastOcc(arr, n, k);

    return pair<int, int>(first, last);
}

int main()
{
    // vector<int> arr = {0, 5, 5, 6, 6, 6};
    // pair<int, int> p = firstAndLastPosition(arr, 6, 2);

    // vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 2};
    // pair<int, int> p = firstAndLastPosition(arr, 8, 2);

    vector<int> arr = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5};
    pair<int, int> p = firstAndLastPosition(arr, 11, 3);

    cout << p.first << " " << p.second;

    return 0;
}