#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);

    cout << "Found 7 at index " << binary_search(v.begin(), v.end(), 7) << endl;

    cout << "Lower bound = " << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;
    cout << "Upper bound = " << upper_bound(v.begin(), v.end(), 7) - v.begin() << endl;

    int a = 5, b = 7;
    cout << "Max = " << max(a, b) << " Min = " << min(a, b) << endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << abcd << endl;

    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "After rotate \n";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end()); // intro sort = quick + heap + insertion sort
    cout << "After sorting \n";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}