#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    unordered_map<string, int> m;

    pair<string, int> p1 = make_pair("RoyalBosS", 0);
    pair<string, int> p2("Ayush", 1);

    m.insert(p1);
    m.insert(p2);
    m["RoyalAyush"] = 2;
    m["RoyalAyush"] = 3;

    for (pair<string, int> i : m)
    {
        cout << i.first << " : " << i.second << endl;
    }

    cout << m["RoyalAyush"] << endl;
    cout << m.at("RoyalAyush") << endl;
    // cout << m.at("BosSAyush") << endl;
    cout << m["BosSAyush"] << endl;
    cout << m.at("BosSAyush") << endl;

    cout << m.count("RoyalBosS") << endl;

    cout << m.size() << endl;
    m.erase("AyushBosS");
    cout << m.size() << endl;

    return 0;
}