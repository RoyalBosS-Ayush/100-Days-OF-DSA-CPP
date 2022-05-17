#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Is Empty? " << q.empty() << endl;
    cout << "Size = " << q.size() << endl;
    cout << "First Element = " << q.front() << endl;

    q.pop();
    cout << "Size after pop = " << q.size() << endl;

    return 0;
}