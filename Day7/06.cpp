#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Is Empty? " << s.empty() << endl;
    cout << "Size = " << s.size() << endl;
    cout << "First Element = " << s.top() << endl;

    s.pop();
    cout << "Size after pop = " << s.size() << endl;

    return 0;
}