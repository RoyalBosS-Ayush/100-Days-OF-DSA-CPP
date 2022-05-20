#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][col]);
            }
        }
        else
        {
            for (int i = 0; i < nRows; i++)
            {
                ans.push_back(arr[i][col]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int rows = 3;
    int cols = 4;

    for (int i : wavePrint(arr, rows, cols))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268