#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if ((ch == '{') || (ch == '(') || (ch == '['))
            s.push(ch);
        else
        {
            if (s.empty())
                return false;

            char top = s.top();
            if ((ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '['))
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104