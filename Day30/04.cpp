#include <iostream>
#include <stack>

using namespace std;

void pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
        myStack.push(x);
    else
    {
        int temp = myStack.top();
        myStack.pop();
        pushAtBottom(myStack, x);
        myStack.push(temp);
    }
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    pushAtBottom(stack, temp);
}

// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875