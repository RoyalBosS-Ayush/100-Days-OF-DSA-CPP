#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

class Solution
{

    int solveOptimal(vector<vector<int>> &a)
    {
        int n = a.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0][1]);

        for (int i = 1; i < n; i++)
        {
            if (a[i][1] > ans.back())
                ans.push_back(a[i][1]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i][1]) - ans.begin();
                ans[index] = a[i][1];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), compare);

        return solveOptimal(envelopes);
    }
};

// https://leetcode.com/problems/russian-doll-envelopes/