#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int> &inputStack, int midPos, int count)
{
    if (count == midPos)
    {
        inputStack.pop();
        return;
    }

    int top = inputStack.top();
    inputStack.pop();

    solve(inputStack, midPos, count + 1);

    inputStack.push(top);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    solve(inputStack, N / 2, 0);
}

// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=1