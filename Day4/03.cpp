#include <iostream>
#include <vector>

using namespace std;

int find_duplicate(vector<int> &arr)
{
    int size = arr.size();
    int sum = 0;
    int sumOfFirstN = (size - 1) * size / 2; // Formula = n*(n+1)2
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum - sumOfFirstN;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2};
    cout << find_duplicate(arr);

    return 0;
}