#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char> &chars)
{
    int i = 0;
    int ansIndex = 0;
    int size = chars.size();

    while (i < size)
    {
        int j = i + 1;
        while (j < size && chars[i] == chars[j])
        {
            j++;
        }

        chars[ansIndex++] = chars[i];

        int count = j - i;

        if (count > 1)
        {
            string str_count = to_string(count);
            for (char i : str_count)
            {
                chars[ansIndex++] = i;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> v1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> v2 = {'a'};
    vector<char> v3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

    cout << compress(v1) << endl;
    cout << compress(v2) << endl;
    cout << compress(v3) << endl;

    return 0;
}

// https://leetcode.com/problems/string-compression/