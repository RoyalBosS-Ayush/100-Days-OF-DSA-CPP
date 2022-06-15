#include <iostream>
#include <queue>

using namespace std;

class kQueue
{
public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        freeSpot = 0;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];

        for (int i = 0; i < n; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    }

    void enqueue(int data, int qn)
    {
        if (freeSpot == -1)
        {
            cout << "Overflow \n";
            return;
        }

        // find free space
        int index = freeSpot;

        // update free space
        freeSpot = next[index];

        // link new element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Underflow \n";
            return -1;
        }

        int index = front[qn - 1];

        // update front
        front[qn - 1] = next[index];

        // manage free space
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main()
{
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;

    q.enqueue(1, 1);
    q.enqueue(2, 2);
    q.enqueue(3, 1);
    q.enqueue(4, 2);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
}