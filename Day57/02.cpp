#include <vector>
#include <unordered_map>

using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> numToCount;

    for (int i = 0; i < arr.size(); i++)
        numToCount[arr[i]]++;

    int maxIndex = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (numToCount[arr[maxIndex]] < numToCount[arr[i]])
            maxIndex = i;
    }
    return arr[maxIndex];
}