#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAX = INT32_MAX;

class Solution
{
    vector<int> nextSmallerElement(int *arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(int *arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n)
    {
        int area = 0;
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            area = max(area, l * b);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int area = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j])
                    M[i][j] += M[i - 1][j];
                else
                    M[i][j] = 0;
            }

            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

// https://practice.geeksforgeeks.org/problems/max-rectangle/1/