#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp = {};
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int s = 0;
    vector<int> arr = {2, -3, 3, 3, -2};

    vector<vector<int>> ans = pairSum(arr, s);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}