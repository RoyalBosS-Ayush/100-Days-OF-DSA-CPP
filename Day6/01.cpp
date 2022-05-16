#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int n, int m, vector<int> time, long long int mid)
{
    int dayCount = 1;
    long long int timeSum = 0;

    for (int i = 0; i < m; i++)
    {
        if (timeSum + time[i] <= mid)
        {
            timeSum += time[i];
        }
        else
        {
            dayCount++;
            if (dayCount > n || time[i] > mid)
            {
                return false;
            }
            timeSum = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
    }
    long long int start = 0, end = sum, mid, ans = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(n, m, time, mid))
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
    int n = 4, m = 7;
    vector<int> time = {2, 2, 3, 3, 4, 4, 1};

    cout << ayushGivesNinjatest(n, m, time);
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574