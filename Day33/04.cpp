#include <iostream>

using namespace std;

class Queue
{
public:
    int data;
    Queue *next;

    Queue(int data)
    {
        this->data = data;
        next = NULL;
    }
};

bool isEmpty(Queue *front)
{
    return front == NULL;
}

int front(Queue *front)
{
    if (isEmpty(front))
        return -1;

    return front->data;
}

void enqueue(Queue *&front, Queue *&rear, int data)
{
    Queue *temp = new Queue(data);
    if (isEmpty(front))
    {
        front = temp;
    }
    rear = temp;
}

int dequeue(Queue *&front, Queue *&rear)
{
    if (isEmpty(front))
        return -1;

    int data = rear->data;
    if (front == rear)
    {
        delete rear;
        front = NULL;
        rear = NULL;
        return data;
    }

    Queue *temp = front;
    while (temp->next != NULL && temp->next != rear)
    {
        temp = temp->next;
    }

    Queue *next = temp->next;
    delete next;

    rear = temp;

    return data;
}

int main()
{
    Queue *FRONT = NULL, *REAR = NULL;

    cout << "Front = " << front(FRONT) << endl;

    enqueue(FRONT, REAR, 1);
    enqueue(FRONT, REAR, 2);
    cout << "Front = " << front(FRONT) << endl;

    cout << "Popped value = " << dequeue(FRONT, REAR) << endl;
    cout << "Front = " << front(FRONT) << endl;

    cout << "Popped value = " << dequeue(FRONT, REAR) << endl;
    cout << "Front = " << front(FRONT) << endl;
}

// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908