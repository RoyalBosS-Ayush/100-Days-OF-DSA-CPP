#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    cout << "MAX HEAP \n";
    maxi.push(1);
    maxi.push(3);
    maxi.push(4);
    maxi.push(2);

    int size = maxi.size();
    for (int i = 0; i < size; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << "\n Empty? " << maxi.empty() << endl;

    cout << "\nMIN HEAP \n";
    mini.push(1);
    mini.push(3);
    mini.push(4);
    mini.push(2);
    int size2 = mini.size();
    for (int i = 0; i < size2; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << "\n Empty? " << mini.empty() << endl;

    return 0;
}