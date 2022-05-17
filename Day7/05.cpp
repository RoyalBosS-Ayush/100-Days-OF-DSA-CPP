#include <iostream>
#include <list>

using namespace std;

void print_l(list<int> l)
{
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(4);

    print_l(l);

    cout << "Is Empty? " << l.empty() << endl;
    cout << "First Element = " << l.front() << endl;
    cout << "Last Element = " << l.back() << endl;

    print_l(l);

    l.pop_back();
    l.pop_front();

    print_l(l);

    l.erase(l.begin());

    print_l(l);

    return 0;
}