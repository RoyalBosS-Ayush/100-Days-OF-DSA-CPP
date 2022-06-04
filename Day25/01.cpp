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

Node *kReverse(Node *head, int k)
{
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (count < k && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (curr != NULL)
    {
        head->next = kReverse(next, k);
    }

    return prev;
}

void print(Node *HEAD)
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *HEAD = NULL;
    Node *TAIL = NULL;

    insertAtTail(HEAD, TAIL, 1); // 1
    insertAtTail(HEAD, TAIL, 2); // 1 2
    insertAtTail(HEAD, TAIL, 3); // 1 2 3
    insertAtTail(HEAD, TAIL, 4); // 1 2 3 4
    insertAtTail(HEAD, TAIL, 5); // 1 2 3 4 5
    insertAtTail(HEAD, TAIL, 6); // 1 2 3 4 5 6

    HEAD = kReverse(HEAD, 2);

    print(HEAD);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644