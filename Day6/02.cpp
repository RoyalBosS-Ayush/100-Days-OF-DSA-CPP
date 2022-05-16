#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &boards, int k, int size, int mid)
{
    int painterCount = 1, timeSum = 0;

    for (int i = 0; i < size; i++)
    {
        if (timeSum + boards[i] <= mid)
        {
            timeSum += boards[i];
        }
        else
        {
            painterCount++;
            if (painterCount > k || boards[i] > mid)
            {
                return false;
            }
            timeSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int size = boards.size(), sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += boards[i];
    }
    int start = 0, end = sum, mid, ans = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(boards, k, size, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int k = 2;
    vector<int> boards = {10, 20, 30, 40};

    cout << findLargestMinDistance(boards, k);
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557