#include <vector>
#include <queue>

using namespace std;

int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;

    int option1 = cost[0] + solve(n, days, cost, index + 1);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solve(n, days, cost, i);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solveMem(n, days, cost, i, dp);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int solveTab(int n, vector<int> &days, vector<int> &cost, int index)
{

    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k + 1];

        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int option2 = cost[1] + dp[i];

        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int solveFast(int n, vector<int> &days, vector<int> &cost)
{
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }
        while (!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    //     return solve(n, days, cost, 0);

    //     vector<int> dp(n+1, -1);
    //     return solveMem(n, days, cost, 0, dp);

    //     return solveTab(n, days, cost, 0);

    return solveFast(n, days, cost);
}

// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776