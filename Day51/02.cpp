void heapify(vector<int> &arr, int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[i] > arr[left])
    {
        swap(arr[left], arr[i]);
        heapify(arr, size, left);
    }
    if (right < size && arr[i] > arr[right])
    {
        swap(arr[right], arr[i]);
        heapify(arr, size, right);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    return arr;
}
