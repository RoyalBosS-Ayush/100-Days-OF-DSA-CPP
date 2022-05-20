#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0, col = cols - 1;

    while (row < rows && col >= 0)
    {
        int element = matrix[row][col];

        if (element == target)
        {
            return 1;
        }
        else if (target < element)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;

    cout << searchMatrix(matrix, target);
    return 0;
}