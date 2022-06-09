#include <stack>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
            s.pop();

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581