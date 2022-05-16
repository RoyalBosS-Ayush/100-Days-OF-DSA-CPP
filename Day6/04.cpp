#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &rank, int m, int size, int mid)
{
    int totalDish = 0;

    for (int i = 0; i < size; i++)
    {
        int timeCount = 0;
        int dishByCook = 0;
        while (true)
        {
            int newDishTime = (dishByCook + 1) * rank[i];
            if (timeCount + newDishTime > mid)
            {
                break;
            }
            timeCount += newDishTime;
            dishByCook++;
            totalDish++;
            if (totalDish == m)
            {
                return true;
            }
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    int size = rank.size(), start = 0, end = m * (m + 1) * rank[0] / 2, mid, ans = end;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(rank, m, size, mid))
        {
            if (ans > mid)
            {
                ans = mid;
            }
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
    // int m = 11;
    // vector<int> rank = {1, 2, 3, 4};

    // int m = 1;
    // vector<int> rank = {10};

    // int m = 10;
    // vector<int> rank = {1, 2, 3, 4};

    int m = 8;
    vector<int> rank = {1, 1, 1, 1, 1, 1, 1, 1};

    cout << minCookTime(rank, m);
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174