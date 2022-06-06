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

// Node *sortList(Node *head)
// {
//     int count0 = 0, count1 = 0, count2 = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//             count0 += 1;
//         else if (temp->data == 1)
//             count1 += 1;
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp != NULL)
//     {
//         if (count0 > 0)
//         {
//             temp->data = 0;
//             count0--;
//         }
//         else if (count1 > 0)
//         {
//             temp->data = 1;
//             count1--;
//         }
//         else
//         {
//             temp->data = 2;
//         }

//         temp = temp->next;
//     }

//     return head;
// }

void insertAtTail(Node *&tail, Node *&temp)
{
    tail->next = temp;
    tail = temp;
}

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            insertAtTail(zeroTail, temp);
        else if (temp->data == 1)
            insertAtTail(oneTail, temp);
        else
            insertAtTail(twoTail, temp);
        temp = temp->next;
    }

    if (oneHead->next == NULL)
        zeroTail->next = twoHead->next;
    else
        zeroTail->next = oneHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
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

    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 1);
    insertAtTail(HEAD, TAIL, 0);
    insertAtTail(HEAD, TAIL, 0);
    insertAtTail(HEAD, TAIL, 0); // 2 2 1 0 0 0

    print(HEAD);

    HEAD = sortList(HEAD);

    print(HEAD);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1