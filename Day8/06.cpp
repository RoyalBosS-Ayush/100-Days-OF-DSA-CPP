#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &v)
{
    int s = 0, e = v.size() - 1;
    while (s < e)
    {
        swap(v[s++], v[e--]);
    }
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1, j = m - 1, carry = 0;
    vector<int> ans;

    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        i--;
    }

    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        j--;
    }

    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum %= 10;
        if (sum)
        {
            ans.push_back(sum);
        }
    }

    reverse(ans);
    return ans;
}

int main()
{
    vector<int> v1 = {4, 5, 1};
    vector<int> v2 = {3, 4, 5};

    for (int i : findArraySum(v1, 3, v2, 3))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186