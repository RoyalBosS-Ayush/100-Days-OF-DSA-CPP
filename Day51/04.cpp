#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "Top: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top: " << minHeap.top() << endl;
    cout << "Size: " << minHeap.size() << endl;
    if (minHeap.empty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;

    return 0;
}