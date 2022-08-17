#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    bool check(vector<int> &base, vector<int> &newBox)
    {
        return (newBox[0] <= base[0]) && (newBox[1] <= base[1]) && (newBox[2] <= base[2]);
    }

    int solve(int n, vector<vector<int>> &a)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(a[curr], a[prev]))
                    include = a[curr][2] + nextRow[curr + 1];

                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return currRow[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (int i = 0; i < cuboids.size(); i++)
        {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
    }
};

// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/