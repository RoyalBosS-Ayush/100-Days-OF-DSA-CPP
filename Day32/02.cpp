#include <stack>
using namespace std;

class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else
                s.push(data);
        }
    }

    int pop()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        s.pop();

        if (curr > mini)
            return curr;
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        return curr < mini ? mini : curr;
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};