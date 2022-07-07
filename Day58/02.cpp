#include <unordered_map>
#include <vector>

using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k)
{
    int minOccurence = n / k;
    unordered_map<int, int> numToCount;
    for (int i : arr)
        numToCount[i]++;

    vector<int> ans;
    for (pair<int, int> i : numToCount)
    {
        if (i.second >= minOccurence)
            ans.push_back(i.first);
    }
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/elements-occur-more-than-n-k-times_1113146