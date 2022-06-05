#include <iostream>
#include <map>

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

// Node *removeDuplicates(Node *head)
// {
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         Node *prev = curr;
//         while (prev->next != NULL)
//         {
//             if (prev->next->data == curr->data)
//             {
//                 Node *temp = prev->next;
//                 prev->next = temp->next;
//                 delete temp;
//             }
//             else
//             {
//                 prev = prev->next;
//             }
//         }
//         curr = curr->next;
//     }
//     return head;
// }

Node *removeDuplicates(Node *head)
{
    map<int, bool> visited;
    Node *prev = head;
    Node *curr = head->next;

    visited[prev->data] = true;

    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            visited[curr->data] = true;
            prev = prev->next;
        }
        curr = prev->next;
    }
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

    insertAtTail(HEAD, TAIL, 1);
    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 1);
    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 7);
    insertAtTail(HEAD, TAIL, 7);
    insertAtTail(HEAD, TAIL, -1);

    // 1 2 1 2 2 2 7 7 - 1

    print(HEAD);

    HEAD = removeDuplicates(HEAD);

    print(HEAD);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331