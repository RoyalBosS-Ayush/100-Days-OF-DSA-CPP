#include <unordered_map>
#include <vector>

using namespace std;

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
{
    unordered_map<int, bool> numToBool;

    for (int i : arr1)
        numToBool[i] = true;

    for (int i : arr2)
        numToBool[i] = true;

    int commonCount = arr1.size() + arr2.size() - numToBool.size();
    int unionCount = numToBool.size();
    return make_pair(commonCount, unionCount);
}

// https://www.codingninjas.com/codestudio/problems/find-similarities-between-two-arrays_1229070