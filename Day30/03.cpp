#include <iostream>
#include <stack>

using namespace std;

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
        myStack.push(x);
    else
    {
        int temp = myStack.top();
        myStack.pop();
        myStack = pushAtBottom(myStack, x);
        myStack.push(temp);
    }
    return myStack;
}

// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166