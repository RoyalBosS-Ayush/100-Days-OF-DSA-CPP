#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, int val, vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        // col check
        if (board[i][col] == val)
            return false;

        // row check
        if (board[row][i] == val)
            return false;

        // 3*3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(i, j, val, board))
                    {
                        board[i][j] = val;

                        if (solve(board))
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

// https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919

// T = O(9^m) [m = number of empty spaces]
// S = O(1)