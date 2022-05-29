#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &visited)
{
    return ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1));
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    if (isSafe(x + 1, y, m, n, visited)) // down
    {
        path.push_back('D');
        solve(m, n, ans, x + 1, y, visited, path);
        path.pop_back();
    }

    if (isSafe(x - 1, y, m, n, visited)) // up
    {
        path.push_back('U');
        solve(m, n, ans, x - 1, y, visited, path);
        path.pop_back();
    }

    if (isSafe(x, y - 1, m, n, visited)) // left
    {
        path.push_back('L');
        solve(m, n, ans, x, y - 1, visited, path);
        path.pop_back();
    }

    if (isSafe(x, y + 1, m, n, visited)) // right
    {
        path.push_back('R');
        solve(m, n, ans, x, y + 1, visited, path);
        path.pop_back();
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> visited = m;
    int srcx = 0, srcy = 0;
    string path = "";

    if (m[0][0] == 0)
    {
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    solve(m, n, ans, srcx, srcy, visited, path);

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int N = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> ans = findPath(m, N);

    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1