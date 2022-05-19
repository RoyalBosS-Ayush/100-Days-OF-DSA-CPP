#include <iostream>
#include <vector>

using namespace std;

char getMaxOccuringChar(string str)
{
    int occurrence[26] = {0};
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        int temp = str[i] - 'a';
        occurrence[temp]++;
    }

    int maxIndex = 0;
    for (int i = 1; i < 26; i++)
    {
        if (occurrence[maxIndex] < occurrence[i])
        {
            maxIndex = i;
        }
    }
    return 'a' + maxIndex;
}

int main()
{
    string str = "royalboss";
    cout << getMaxOccuringChar(str);
    return 0;
}

// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1