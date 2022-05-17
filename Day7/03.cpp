#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        cout << "Loop " << i + 1 << " Capacity " << v.capacity() << " Size " << v.size() << endl;
    }

    cout << "Element at index 3 is " << v.at(3) << endl;
    cout << "Is Empty? " << v.empty() << endl;
    cout << "First Element = " << v.front() << endl;
    cout << "Last Element = " << v.back() << endl;

    cout << "\nBefore Pop\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    v.pop_back();

    cout << "\nAfter Pop\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\n\nBefore Clearing\n";
    cout << "Size=" << v.size() << " Capacity=" << v.capacity();

    v.clear();

    cout << "\nAdter Clearing\n";
    cout << "Size=" << v.size() << " Capacity=" << v.capacity();

    return 0;
}