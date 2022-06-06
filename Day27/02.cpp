#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

void insertAtTail(Node<int> *&HEAD, Node<int> *&TAIL, int data)
{
    Node<int> *temp = new Node<int>(data);

    if (HEAD == NULL)
        HEAD = temp;
    else
        TAIL->next = temp;
    TAIL = temp;
}

Node<int> *solve(Node<int> *first, Node<int> *second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node<int> *curr1 = first;
    Node<int> *curr2 = second;
    Node<int> *next1 = curr1->next;
    Node<int> *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr1->next;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                break;
            }
        }
    }
    return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
    {
        return second;
    }
    else if (second == NULL)
    {
        return first;
    }

    if (first->data < second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

void print(Node<int> *HEAD)
{
    Node<int> *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node<int> *HEAD1 = NULL;
    Node<int> *TAIL1 = NULL;
    Node<int> *HEAD2 = NULL;
    Node<int> *TAIL2 = NULL;

    insertAtTail(HEAD1, TAIL1, 1);
    insertAtTail(HEAD1, TAIL1, 4);
    insertAtTail(HEAD1, TAIL1, 5); // 1 4 5

    insertAtTail(HEAD2, TAIL2, 2);
    insertAtTail(HEAD2, TAIL2, 3);
    insertAtTail(HEAD2, TAIL2, 5); // 2 3 5

    print(HEAD1);
    print(HEAD2);

    HEAD1 = sortTwoLists(HEAD1, HEAD2);

    print(HEAD1);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0