#include <iostream>
#include <vector>

using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 4, 7};
    vector<int> arr2 = {2, 3, 3, 3, 5, 6, 7};

    for (int i : findArrayIntersection(arr1, 5, arr2, 7))
    {
        cout << i << " ";
    }

    return 0;
}