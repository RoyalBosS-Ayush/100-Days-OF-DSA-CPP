#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &arr, int &n, vector<string> &ans, vector<vector<bool>> &visited)
{
    return x < n && y < n && x >= 0 && y >= 0 && visited[x][y] == 0 && arr[x][y];
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    if (isSafe(x + 1, y, arr, n, ans, visited)) // down
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }

    if (isSafe(x, y - 1, arr, n, ans, visited)) // left
    {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }

    if (isSafe(x, y + 1, arr, n, ans, visited)) // right
    {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }

    if (isSafe(x - 1, y, arr, n, ans, visited)) // up
    {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }

    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
        return ans;

    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}

// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030