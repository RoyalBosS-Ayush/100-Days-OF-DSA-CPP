#include <iostream>
#include <stack>

using namespace std;

void sortedPush(stack<int> &myStack, int x)
{
    if (myStack.empty())
        myStack.push(x);
    else
    {
        int top = myStack.top();
        if (x < top)
        {
            myStack.pop();
            sortedPush(myStack, x);
            myStack.push(top);
        }
        else
            myStack.push(x);
    }
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    sortedPush(stack, temp);
}

// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275