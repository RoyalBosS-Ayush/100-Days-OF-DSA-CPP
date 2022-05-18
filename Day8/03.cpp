#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int size = nums.size();
    int firstZero = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i])
        {
            swap(nums[firstZero], nums[i]);
            firstZero++;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeroes(arr);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/move-zeroes/