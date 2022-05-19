#include <iostream>

using namespace std;

char toLowerCase(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
    {
        return c;
    }
    return c + 32;
}

bool isAlphaNumberic(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

bool checkPalindrome(string s)
{
    int start = 0, end = s.length() - 1;

    while (start < end)
    {
        if (!isAlphaNumberic(s[start]))
        {
            start++;
            continue;
        }
        if (!isAlphaNumberic(s[end]))
        {
            end--;
            continue;
        }
        if (toLowerCase(s[start++]) != toLowerCase(s[end--]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "c1 O$d@eeD o1c";
    cout << checkPalindrome(s);
    // cout << toLowerCase(s[0]);

    return 0;
}

// https://leetcode.com/problems/valid-palindrome/