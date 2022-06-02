#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        if (this->prev != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
    }
};
Node *HEAD = NULL;
Node *TAIL = NULL;

void print()
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    if (HEAD != NULL && TAIL != NULL)
        cout << "HEAD " << HEAD->data << " TAIL " << TAIL->data << endl;
}

void reversePrint()
{
    Node *temp = TAIL;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int getLength()
{
    Node *temp = HEAD;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(int data)
{
    Node *temp = new Node(data);
    temp->next = HEAD;
    if (HEAD != NULL)
    {
        HEAD->prev = temp;
    }
    HEAD = temp;

    if (TAIL == NULL)
    {
        TAIL = temp;
    }
}

void insertAtTail(int data)
{
    Node *temp = new Node(data);
    temp->prev = TAIL;
    if (TAIL != NULL)
    {
        TAIL->next = temp;
    }
    TAIL = temp;

    if (HEAD == NULL)
    {
        HEAD->prev = temp;
    }
}

void insertAtMid(int position, int data)
{
    if (position == 1)
    {
        insertAtHead(data);
        return;
    }
    Node *curr = HEAD;
    int i = 1;
    while (i < position - 1)
    {
        curr = curr->next;
        i++;
    }

    if (curr->next == NULL)
    {
        insertAtTail(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next->prev = temp;
    curr->next = temp;
}

void deleteNode(int position)
{
    if (position == 1)
    {
        Node *temp = HEAD;
        HEAD = HEAD->next;
        if (HEAD == NULL)
            TAIL = NULL;
        else
            HEAD->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node *curr = HEAD;
    Node *prev = NULL;
    while (i < position)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (curr == TAIL)
        TAIL = prev;
    else
        curr->next->prev = prev;
    prev->next = curr->next;
    curr->prev = NULL;
    curr->next = NULL;

    delete curr;
}

int main()
{

    insertAtHead(1); // 1
    print();
    insertAtHead(2); // 2 1
    print();
    insertAtTail(3); // 2 1 3
    print();

    insertAtMid(1, 4); // 4 2 1 3
    print();
    insertAtMid(3, 5); // 4 2 5 1 3
    print();
    insertAtMid(6, 6); // 4 2 5 1 3 6
    print();

    // cout << getLength() << endl;
    // reversePrint();

    deleteNode(1); // 2 5 1 3 6
    deleteNode(3); // 2 5 3 6
    deleteNode(4); // 2 5 3

    print();
    reversePrint(); // 3 5 2

    deleteNode(1); // 5 3
    deleteNode(1); // 3
    deleteNode(1); //
    print();
    return 0;
}