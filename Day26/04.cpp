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

Node *splitLL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    Node *tail = temp;
    temp = head;
    count /= 2;
    while (count > 0)
    {
        temp = temp->next;
        count--;
    }

    tail->next = temp->next;
    temp->next = head;

    return tail->next;
}

void print(Node *HEAD)
{
    Node *temp = HEAD;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != HEAD);
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

    TAIL->next = HEAD; // 1 2 3 4 5 6 1

    print(HEAD);

    Node *splitHead = splitLL(HEAD);

    print(HEAD);
    print(splitHead);

    return 0;
}