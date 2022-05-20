#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> ans = matrix;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans[i][j] = matrix[cols - j - 1][i];
        }
    }

    matrix = ans;
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);

    for (auto i : matrix)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}