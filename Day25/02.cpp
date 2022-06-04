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

// bool circularLL(Node *head)
// {
//     if (head == NULL)
//     {
//         return true;
//     }

//     Node *temp = head;

//     do
//     {
//         if (temp == NULL)
//         {
//             return false;
//         }
//         temp = temp->next;
//     } while (temp != head);
//     return true;
// }

bool circularLL(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *slowPointer = head,
         *fastPointer = head;

    while (slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer)
            return 1;
    }

    return 0;
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

    print(HEAD);

    cout << "isCircular? " << circularLL(HEAD) << endl;

    TAIL->next = HEAD->next->next;

    cout << "isCircular? " << circularLL(HEAD) << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/is-it-a-circular-linked-list_981265