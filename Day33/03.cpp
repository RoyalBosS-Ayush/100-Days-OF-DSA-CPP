class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool pushFront(int x)
    {
        if (isFull())
            return false;

        else if (isEmpty())
            front = rear = 0;
        else if (front == 0 && rear != size - 1)
            front = size - 1;
        else
            front--;

        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull())
            return false;

        else if (isEmpty())
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;

        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
            return -1;

        int ans = arr[front];

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }

    int popRear()
    {
        if (isEmpty())
            return -1;

        int ans = arr[rear];

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;

        return ans;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (rear == front - 1));
    }
};

// https://www.codingninjas.com/codestudio/problems/deque_1170059?leftPanelTab=1