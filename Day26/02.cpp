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

Node * uniqueSortedList(Node * head) {
    Node *curr = head;
    while(curr != NULL && curr->next != NULL){
        if (curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
        curr = curr->next;
        }
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

    insertAtTail(HEAD, TAIL, 2); // 2
    insertAtTail(HEAD, TAIL, 5); // 2 5
    insertAtTail(HEAD, TAIL, 5); // 2 5 5
    insertAtTail(HEAD, TAIL, 5); // 2 5 5 5
    insertAtTail(HEAD, TAIL, 5); // 2 5 5 5 5
    insertAtTail(HEAD, TAIL, -1); // 2 5 5 5 5 -1

    print(HEAD);

    HEAD = uniqueSortedList(HEAD);

    print(HEAD);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283