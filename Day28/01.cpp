#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (tail == NULL)
    {
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *copyList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *original = head;
    while (original != NULL)
    {
        insertAtTail(cloneHead, cloneTail, original->data);
        original = original->next;
    }

    unordered_map<Node *, Node *> old2new;
    original = head;
    Node *clone = cloneHead;

    while (original != NULL)
    {
        old2new[original] = clone;
        original = original->next;
        clone = clone->next;
    }

    original = head;
    clone = cloneHead;

    while (clone != NULL)
    {
        clone->arb = old2new[original->arb];
        clone = clone->next;
        original = original->next;
    }

    return cloneHead;
}

// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1