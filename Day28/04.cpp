#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = temp->child;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = temp->child;
            right = right->child;
        }
    }
    temp->next = NULL;

    if (left)
        temp->child = left;
    else if (right)
        temp->child = right;

    ans = ans->child;
    return ans;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL)
        return head;

    head->next = flattenLinkedList(head->next);
    Node *ans = merge(head, head->next);
    return head;
}

// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655