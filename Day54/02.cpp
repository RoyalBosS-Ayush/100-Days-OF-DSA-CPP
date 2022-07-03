#include <queue>

class greaterNode
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};

Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    priority_queue<Node<int> *, vector<Node<int> *>, greaterNode> minHeap;
    Node<int> *head = NULL, *tail = NULL;

    for (int i = 0; i < listArray.size(); i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    while (minHeap.size() > 0)
    {
        Node<int> *top = minHeap.top();
        minHeap.pop();

        if (head == NULL)
        {
            head = tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }
    }

    return head;
}

// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772