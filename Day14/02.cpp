#include <iostream>
#include <vector>

using namespace std;

// jagged array

int main()
{
    int rows;
    cout << "Enter Rows: ";
    cin >> rows;

    int **arr = new int *[rows];
    int *cols = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        int noOfCols;
        cout << "Number of rows in column " << i + 1 << ": ";
        cin >> noOfCols;
        cols[i] = noOfCols;
        arr[i] = new int[noOfCols];
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter Elements for row " << i + 1 << ": ";
        for (int j = 0; j < cols[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}