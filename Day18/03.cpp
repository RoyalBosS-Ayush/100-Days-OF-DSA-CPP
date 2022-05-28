#include <iostream>
#include <vector>

using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= digits.length())
    {
        if (output != "")
            ans.push_back(output);
        return;
    }

    int mappingIndex = digits[index] - '0';
    string value = mapping[mappingIndex];

    for (char i : value)
    {
        output.push_back(i);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, ans, mapping);

    return ans;
}

int main()
{
    string str = "23";
    vector<string> ans = letterCombinations(str);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/