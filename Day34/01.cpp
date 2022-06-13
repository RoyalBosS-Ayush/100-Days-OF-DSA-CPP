struct Queue *rev(struct Queue *Q)
{
    if (size(Q) == 1)
        return Q;

    int temp = front(Q);
    dequeue(Q);
    Q = rev(Q);
    enqueue(Q, temp);
    return Q;
}

// https://practice.geeksforgeeks.org/problems/queue-reversal/1