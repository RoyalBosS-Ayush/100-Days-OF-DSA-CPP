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

void insertAtMid(int position, int data)
{
    if (position == 1)
    {
        insertAtHead(data);
        return;
    }
    Node *temp = HEAD;
    Node *newNode = new Node(data);
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(data);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

    insertAtMid(3, 5); // 3 1 5 2 4
    print();

    insertAtMid(1, 6); // 6 3 1 5 2 4
    insertAtMid(7, 7); // 6 3 1 5 2 4 7
    print();

    return 0;
}