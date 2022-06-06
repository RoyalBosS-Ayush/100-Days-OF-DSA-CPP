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

Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *nextt = NULL;

    while (curr != NULL)
    {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *mid = getMid(head);
    mid->next = reverse(mid->next);

    Node *head1 = head;
    Node *head2 = mid->next;
    while (head2 != NULL && head1 != head2)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    mid->next = reverse(mid->next);
    return true;
}

int main()
{

    Node *HEAD = NULL;
    Node *TAIL = NULL;

    insertAtTail(HEAD, TAIL, 1);
    insertAtTail(HEAD, TAIL, 2);
    insertAtTail(HEAD, TAIL, 1); // 1 2 1

    print(HEAD);
    cout << isPalindrome(HEAD) << endl;

    insertAtTail(HEAD, TAIL, 2); // 1 2 1 2

    print(HEAD);
    cout << isPalindrome(HEAD) << endl;

    return 0;
}

// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/#