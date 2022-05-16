#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isPossible(vector<int> &stalls, int k, int size, int mid)
{
    int cowCount = 1, lastPos = stalls[0];

    for (int i = 0; i < size; i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int size = stalls.size(), start = 0, end = stalls[size - 1], mid, ans = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(stalls, k, size, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int k = 2;
    vector<int> stalls = {4, 2, 1, 3, 6};

    cout << aggressiveCows(stalls, k);
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559