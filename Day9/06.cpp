#include <iostream>
#include <vector>

using namespace std;

string replaceSpaces(string &str)
{
    string s;
    int size = str.length();
    for (char i : str)
    {
        if (i == ' ')
        {
            s.push_back('@');
            s.push_back('4');
            s.push_back('0');
        }
        else
        {
            s.push_back(i);
        }
    }
    return s;
}

int main()
{
    string s = "Coding Ninjas Is A Coding Platform";
    cout << replaceSpaces(s) << endl;
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172