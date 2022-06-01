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

Node *HEAD = NULL;
Node *TAIL = NULL;

void insertAtHead(int data)
{
    Node *temp = new Node(data);

    if (TAIL == NULL)
    {
        TAIL = temp;
    }
    temp->next = HEAD;
    HEAD = temp;
}

void insertAtTail(int data)
{
    Node *temp = new Node(data);

    if (HEAD == NULL)
    {
        HEAD = temp;
    }
    TAIL->next = temp;
    TAIL = temp;
}

void print()
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "HEAD " << HEAD->data << " TAIL " << TAIL->data << endl;
}

int main()
{
    insertAtHead(1); // 1
    insertAtTail(2); // 1 2
    insertAtHead(3); // 3 1 2
    insertAtTail(4); // 3 1 2 4
    print();

    return 0;
}