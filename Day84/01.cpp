#include <vector>

using namespace std;

long long int solve(vector<int> &nums, int s, int e)
{
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[s];

    for (int i = s + 1; i < e; i++)
    {
        long long int incl = prev2 + nums[i];
        long long int excl = prev1;

        long long int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    return max(solve(valueInHouse, 0, n - 1), solve(valueInHouse, 1, n));
}

// https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=1
// T = O(n)
// S = O(1)