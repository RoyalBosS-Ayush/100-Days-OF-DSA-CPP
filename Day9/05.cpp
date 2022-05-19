#include <iostream>

using namespace std;

int main()
{
    string s;
    char ch[50];
    cout << "Enter something: ";
    cin.getline(ch, 50);
    cout << ch;

    // getline(cin, s, '\t');
    // cout << s;
    return 0;
}