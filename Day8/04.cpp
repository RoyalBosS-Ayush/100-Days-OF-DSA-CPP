#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    vector<int> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp[(i + k) % (size)] = nums[i];
    }
    nums = temp;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/rotate-array/