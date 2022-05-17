#include <iostream>
#include <deque>

using namespace std;

void print_d(deque<int> d)
{
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);

    print_d(d);

    cout << "Element at index 3 is " << d.at(3) << endl;
    cout << "Is Empty? " << d.empty() << endl;
    cout << "First Element = " << d.front() << endl;
    cout << "Last Element = " << d.back() << endl;

    print_d(d);

    d.pop_back();
    d.pop_front();

    print_d(d);

    d.erase(d.begin(), d.end());
    cout << "Is Empty? " << d.empty() << endl;
    cout << "Size=" << d.size();

    return 0;
}