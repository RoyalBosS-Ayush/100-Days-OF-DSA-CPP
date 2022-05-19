#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char> &s)
{
    int start = 0, end = s.size() - 1;

    while (start < end)
    {
        swap(s[start++], s[end--]);
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);

    for (char i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/reverse-string/