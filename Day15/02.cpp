#include <iostream>

using namespace std;

int countDistinctWayToClimbStair(long long nStairs)
{
    if (nStairs < 0)
    {
        return 0;
    }
    else if (nStairs == 0)
    {
        return 1;
    }

    return countDistinctWayToClimbStair(nStairs - 1) + countDistinctWayToClimbStair(nStairs - 2);
}

int main()
{
    long long int nStairs = 5;
    cout << countDistinctWayToClimbStair(nStairs) << endl;
    return 0;
}