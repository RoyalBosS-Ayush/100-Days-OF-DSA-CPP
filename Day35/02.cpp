#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    stack<int> s;
    int halfSize = q.size() / 2;

    // queue:16 17 18 19 20
    // stack: 15 14 13 12 11
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // queue: 16 17 18 19 20, stack: 11 12 13 14 15
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
