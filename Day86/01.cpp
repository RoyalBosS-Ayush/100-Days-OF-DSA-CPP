#define MOD 1000000007
#include <vector>

using namespace std;

long long int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int ans = ((n - 1) % MOD) * ((solve(n - 1) % MOD + solve(n - 2) % MOD));
    return ans;
}

long long int solveMem(int n, vector<long long int> &dp)
{
    if (dp[n] != -1)
        return dp[n];

    dp[n] = ((n - 1) % MOD) * ((solveMem(n - 1, dp) % MOD + solveMem(n - 2, dp) % MOD));
    return dp[n];
}

long long int solveTab(int n)
{
    vector<long long int> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long first = dp[i - 1] % MOD;
        long long second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        dp[i] = ((i - 1) * sum) % MOD;
    }
    return dp[n];
}

long long int solveFast(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long first = prev1 % MOD;
        long long second = prev2 % MOD;
        long long int ans = ((i - 1) * (first + second)) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n)
{
    //     return solve(n);

    //     vector<long long int> dp(n+1, -1);
    //     dp[1] = 0;
    //     dp[2] = 1;
    //     return solveMem(n, dp);

    //     return solveTab(n);

    return solveFast(n);
}

// https://www.codingninjas.com/codestudio/problems/count-derangements_873861