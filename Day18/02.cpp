#include <iostream>
#include <vector>

using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        if (output != "")
            ans.push_back(output);
        return;
    }

    solve(str, output, index + 1, ans); // exclude

    int element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans); // include
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output;
    int index = 0;

    solve(str, output, index, ans);

    return ans;
}

int main()
{
    string str = "abc";
    vector<string> ans = subsequences(str);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087