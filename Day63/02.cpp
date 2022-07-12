#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int &n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp.push_back(board[i][j]);

    ans.push_back(temp);
}

bool isSafe(int row, int col, int n, unordered_map<int, bool> &queenInRow, unordered_map<int, bool> &queenAtAcuteDiagonal, unordered_map<int, bool> &queenAtObtuseDiagonal)
{
    // left check
    if (queenInRow[row])
        return false;

    // top left diagonal check
    if (queenAtObtuseDiagonal[(n - 1 + col - row)])
        return false;

    // bottom left diagonal check
    if (queenAtAcuteDiagonal[(row + col)])
        return false;

    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n, unordered_map<int, bool> &queenInRow, unordered_map<int, bool> &queenAtAcuteDiagonal, unordered_map<int, bool> &queenAtObtuseDiagonal)
{
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, queenInRow, queenAtAcuteDiagonal, queenAtObtuseDiagonal))
        {
            queenInRow[row] = 1;
            queenAtAcuteDiagonal[(row + col)] = 1;
            queenAtObtuseDiagonal[(n - 1 + col - row)] = 1;
            board[row][col] = 1;
            solve(col + 1, board, ans, n, queenInRow, queenAtAcuteDiagonal, queenAtObtuseDiagonal);
            queenAtObtuseDiagonal[(n - 1 + col - row)] = 0;
            queenInRow[row] = 0;
            queenAtAcuteDiagonal[(row + col)] = 0;
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    unordered_map<int, bool> queenInRow;
    unordered_map<int, bool> queenAtAcuteDiagonal;
    unordered_map<int, bool> queenAtObtuseDiagonal;

    solve(0, board, ans, n, queenInRow, queenAtAcuteDiagonal, queenAtObtuseDiagonal);
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286