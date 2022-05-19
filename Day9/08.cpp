#include <iostream>
#include <vector>

using namespace std;

bool checkEqual(int arr1[26], int arr2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0}, count2[26] = {0};

    for (char i : s1)
    {
        int index = i - 'a';
        count1[index]++;
    }

    int i = 0;
    int windowSize = s1.length();
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if (checkEqual(count1, count2))
    {
        return true;
    }

    while (i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        if (checkEqual(count1, count2))
        {
            return true;
        }

        i++;
    }
    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";

    cout << checkInclusion(s1, s2);
    return 0;
}