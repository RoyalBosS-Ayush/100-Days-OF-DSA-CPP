#include <iostream>

using namespace std;

bool checkPalindrome(string &str, int j)
{
    int strLen = str.length();
    if (strLen / 2 <= j)
    {
        if (str[strLen - j - 1] == str[j])
        {
            return checkPalindrome(str, j - 1);
        }
        return false;
    }
    return true;
}

int main()
{
    string str = "abcba";
    cout << checkPalindrome(str, str.length() - 1) << endl;

    return 0;
}