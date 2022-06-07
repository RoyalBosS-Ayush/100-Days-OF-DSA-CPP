#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(node *&HEAD, node *&TAIL, int data)
{
    node *temp = new node(data);

    if (HEAD == NULL)
        HEAD = temp;
    else
        TAIL->next = temp;
    TAIL = temp;
}

void print(node *HEAD)
{
    node *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *getMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *merge(node *&left, node *&right)
{
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }

    if (left)
        temp->next = left;
    else if (right)
        temp->next = right;

    ans = ans->next;
    return ans;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *mid = getMid(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node *result = merge(left, right);

    return result;
}

int main()
{

    node *HEAD = NULL;
    node *TAIL = NULL;

    insertAtTail(HEAD, TAIL, 1);
    insertAtTail(HEAD, TAIL, 4);
    insertAtTail(HEAD, TAIL, 5);
    insertAtTail(HEAD, TAIL, 2); // 1 4 5 2

    print(HEAD);

    HEAD = mergeSort(HEAD);
    print(HEAD);

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514?leftPanelTab=1