#include <iostream>

using namespace std;

int main()
{
    // initialize entire array to some value
    int arr[20];
    fill_n(arr, 20, 96);
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}