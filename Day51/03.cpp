#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> maxHeap;

    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    cout << "Top: " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "Top: " << maxHeap.top() << endl;
    cout << "Size: " << maxHeap.size() << endl;
    if (maxHeap.empty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;

    return 0;
}