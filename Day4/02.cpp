#include <iostream>

using namespace std;

int getUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[7] = {1, 2, 3, 3, 1, 4, 4};
    cout << getUnique(arr, 7);

    return 0;
}