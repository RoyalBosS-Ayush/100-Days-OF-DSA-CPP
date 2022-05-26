#include <iostream>

using namespace std;

void swapString(string &str, int j)
{
    int strLen = str.length();
    if (strLen / 2 <= j)
    {
        swap(str[strLen - j - 1], str[j]);
        swapString(str, j - 1);
    }
}

string reverseString(string str)
{
    swapString(str, str.length() - 1);
    return str;
}

int main()
{
    string str = "coding";
    cout << reverseString(str) << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927