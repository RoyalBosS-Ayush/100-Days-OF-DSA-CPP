#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtTail(Node *&HEAD, Node *&TAIL, int data)
{
    Node *temp = new Node(data);

    if (HEAD == NULL)
        HEAD = temp;
    else
        TAIL->next = temp;
    TAIL = temp;
}

void reverse(Node *&HEAD, Node *&TAIL)
{
    Node *prev = NULL;
    Node *forward = NULL;
    Node *curr = HEAD;
    TAIL = HEAD;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    HEAD = prev;
}

void reverseList(Node *&Head, Node *&curr, Node *&prev)
{
    if (curr == NULL)
    {
        Head = prev;
        return;
    }

    reverseList(Head, curr->next, curr);
    curr->next = prev;
}

Node *reverse(Node *Head)
{
    Node *curr = Head;
    Node *prev = NULL;
    reverseList(Head, curr, prev);
    return Head;
}

void print(Node *HEAD, Node *TAIL)
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    if (HEAD && TAIL)
        cout << "HEAD " << HEAD->data << " TAIL " << TAIL->data << endl;
}

int main()
{
    Node *HEAD = NULL;
    Node *TAIL = NULL;

    insertAtTail(HEAD, TAIL, 1); // 1
    insertAtTail(HEAD, TAIL, 2); // 1 2
    insertAtTail(HEAD, TAIL, 3); // 1 2 3
    insertAtTail(HEAD, TAIL, 4); // 1 2 3 4

    print(HEAD, TAIL);
    // reverse(HEAD, TAIL);
    print(reverse(HEAD), TAIL);

    return 0;
}