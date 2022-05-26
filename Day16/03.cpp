#include <iostream>

using namespace std;

bool checkPalindrome(long long N)
{
    long long original = N, rev = 0;
    while (original > 0)
    {
        int bit = original & 1;
        rev = rev << 1;
        rev += bit;
        original = original >> 1;
    }
    return N == rev;
}

int main()
{
    long long int N = 7;
    cout << checkPalindrome(N) << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/check-palindrome_920555