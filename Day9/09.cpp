#include <iostream>

using namespace std;

string removeDuplicates(string s)
{
    string ans;

    for (char i : s)
    {
        if (ans.empty() || ans[ans.length() - 1] != i)
        {
            ans.push_back(i);
        }
        else
        {
            ans.pop_back();
        }
        cout << ans.size() << endl;
    }

    return ans;
}

int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s);

    return 0;
}

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/