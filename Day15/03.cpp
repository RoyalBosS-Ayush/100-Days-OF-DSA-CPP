#include <iostream>

using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    sayDigit(n / 10, arr);
    cout << arr[n % 10] << " ";
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n;
    cout << "Enter a number: ";
    cin >> n;

    sayDigit(n, arr);

    return 0;
}