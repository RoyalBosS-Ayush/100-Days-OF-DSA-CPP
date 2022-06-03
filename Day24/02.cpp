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

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    delete temp;
    return count;
}

// Node *findMiddle(Node *head)
// {
//     int mid = getLength(head) / 2;
//     Node *temp = head;
//     for (int i = 0; i < mid; i++)
//     {
//         temp = temp->next;
//     }
//     return temp;
// }

Node *findMiddle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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
    insertAtTail(HEAD, TAIL, 5); // 1 2 3 4 5

    print(HEAD, TAIL);
    cout << "Middle element = " << findMiddle(HEAD)->data << endl;

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250