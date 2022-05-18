#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &nums)
{
    int count = 0, size = nums.size();
    for (int i = 1; i < size; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }

    if (nums[size - 1] > nums[0])
        count++;

    return count <= 1;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << check(nums);

    return 0;
}

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/