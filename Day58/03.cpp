#include <unordered_map>
#include <vector>

using namespace std;

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{

    unordered_map<int, int> arr1ToCount;
    unordered_map<int, int> arr2ToCount;

    for (int i : arr1)
        arr1ToCount[i]++;

    for (int i : arr2)
        arr2ToCount[i]++;

    for (int i = 0; i < m; i++)
    {
        if (arr2ToCount[arr2[i]] > arr1ToCount[arr2[i]])
            return false;
    }

    return true;
}

// https://www.codingninjas.com/codestudio/problems/check-subset_762948