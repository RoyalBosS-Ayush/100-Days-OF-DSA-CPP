#include <vector>

using namespace std;

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;

    if (weight[index] <= capacity)
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = solveMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + curr[w - weight[index]];
            int exclude = curr[w];
            curr[w] = max(include, exclude);
        }
    }

    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    //     vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    //     return solveMem(weight, value, n-1, maxWeight, dp);

    return solveTab(weight, value, n, maxWeight);
}

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542
// T = O(n*w)
// S = O(w)