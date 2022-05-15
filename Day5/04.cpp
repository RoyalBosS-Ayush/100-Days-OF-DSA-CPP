#include <iostream>

using namespace std;

int sqrtN(long long int x)
{
    long long int start = 0, end = x, mid, ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if (square == x)
        {
            return mid;
        }
        else if (square < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    cout << sqrtN(9) << endl;
    cout << sqrtN(10) << endl;
    return 0;
}