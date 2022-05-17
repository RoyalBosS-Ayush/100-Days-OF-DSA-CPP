#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, string> m;

    m["c"] = "cat";
    m["a"] = "apple";
    m["d"] = "dog";
    m["b"] = "ball";

    for (auto i : m)
    {
        cout << i.first << " : " << i.second << endl;
    }
    cout << endl;

    cout << "Before clear b is present? " << m.count("b") << endl;

    m.erase("b");
    cout << "After clear b is present? " << m.count("b") << endl;

    auto itr = m.find("c");
    for (auto it = itr; it != m.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }
    cout << endl;

    return 0;
}