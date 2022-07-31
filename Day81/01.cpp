#include <vector>

using namespace std;

class Solution
{
    int solve(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[n - 2]);
        return min(dp[n - 1], dp[n - 2]);
    }

    int solve2(vector<int> &cost)
    {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // return solve(cost);
        return solve2(cost);
    }
};

// https://leetcode.com/problems/min-cost-climbing-stairs/