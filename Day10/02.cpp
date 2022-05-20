#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int startingRow = 0;
    int endingRow = rows - 1;
    int startingCol = 0;
    int endingCol = cols - 1;
    int count = 0, total = rows * cols;

    while (count < total)
    {
        for (int i = startingCol; i <= endingCol && count < total; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for (int i = startingRow; i <= endingRow && count < total; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for (int i = endingCol; i >= startingCol && count < total; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for (int i = endingRow; i >= startingRow && count < total; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i : spiralOrder(matrix))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}