#include <iostream>
#include <stack>
#include <string>

using namespace std;

int findMinimumCost(string str)
{
    if (str.length() % 2)
        return -1;

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    int opening = 0;
    int closing = 0;

    while (!st.empty())
    {
        st.top() == '{' ? opening++ : closing++;
        st.pop();
    }

    return (opening + 1) / 2 + (closing + 1) / 2;
}

// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=1