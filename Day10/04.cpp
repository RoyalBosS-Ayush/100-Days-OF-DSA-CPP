#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int start = 0, end = (rows * cols - 1), mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int value = matrix[mid / cols][mid % cols];

        if (value == target)
        {
            return true;
        }
        else if (target > value)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    cout << searchMatrix(matrix, target);

    return 0;
}