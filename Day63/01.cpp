#include <iostream>
#include <vector>

using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int &n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp.push_back(board[i][j]);

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // left check
    for (int j = col - 1; j >= 0; j--)
        if (board[row][j])
            return false;

    // top left diagonal check
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    // bottom left diagonal check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, board, ans, n);
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286
// T = O(N!)
// S = O(N*N)