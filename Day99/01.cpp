#include <vector>

using namespace std;

class Solution
{
    int solve(int s, int e, vector<int> &slices, int n)
    {
        if (n == 0 || s > e)
            return 0;

        int include = slices[s] + solve(s + 2, e, slices, n - 1);
        int exclude = solve(s + 1, e, slices, n);
        return max(include, exclude);
    }

    int solveMem(int s, int e, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || s > e)
            return 0;

        if (dp[s][n] != -1)
            return dp[s][n];

        int include = slices[s] + solveMem(s + 2, e, slices, n - 1, dp);
        int exclude = solveMem(s + 1, e, slices, n, dp);
        return dp[s][n] = max(include, exclude);
    }

    int solveTab(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int s = k - 2; s >= 0; s--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int include = slices[s] + dp[s + 2][n - 1];
                int exclude = dp[s + 1][n];
                dp[s][n] = max(include, exclude);
            }
        }

        for (int s = k - 1; s >= 1; s--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int include = slices[s] + dp2[s + 2][n - 1];
                int exclude = dp2[s + 1][n];
                dp2[s][n] = max(include, exclude);
            }
        }

        int case1 = dp[0][k / 3];
        int case2 = dp2[1][k / 3];
        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();

        // int case1 = solve(0, k-2, slices, k/3);
        // int case2 = solve(1, k-1, slices, k/3);
        // return max(case1, case2);

        // vector<vector<int>> dp(k, vector<int> (k, -1));
        // int case1 = solveMem(0, k-2, slices, k/3, dp);
        // vector<vector<int>> dp2(k, vector<int> (k, -1));
        // int case2 = solveMem(1, k-1, slices, k/3, dp2);
        // return max(case1, case2);

        return solveTab(slices);
    }
};

// https://leetcode.com/problems/pizza-with-3n-slices/