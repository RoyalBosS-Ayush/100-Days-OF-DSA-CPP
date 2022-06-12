class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return qfront == rear;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }

        int temp = arr[qfront];
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return temp;
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        return arr[qfront];
    }
};

// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908