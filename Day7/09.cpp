#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    int size = s.size();
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Empty? " << s.empty() << endl;

    cout << "2 is present? " << s.count(2) << endl;

    set<int>::iterator itr = s.find(2);
    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();

    s.erase(it);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}