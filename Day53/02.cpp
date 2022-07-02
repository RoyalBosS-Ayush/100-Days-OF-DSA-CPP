#include <queue>

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mh;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (mh.size() < k)
            {
                mh.push(sum);
            }
            else
            {
                if (sum > mh.top())
                {
                    mh.pop();
                    mh.push(sum);
                }
            }
        }
    }
    return mh.top();
}