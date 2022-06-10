#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
    bool knows(vector<vector<int>> &M, int a, int b)
    {
        return M[a][b];
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
            s.push(i);

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b))
                s.push(b);
            else
                s.push(a);
        }

        int ans = s.top();

        for (int i = 0; i < n; i++)
        {
            if (M[ans][i])
                return -1;
        }

        int oneCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans])
                oneCount++;
        }

        if (oneCount != n - 1)
            return -1;

        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/