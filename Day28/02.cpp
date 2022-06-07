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
    // step1: create clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *original = head;
    while (original != NULL)
    {
        insertAtTail(cloneHead, cloneTail, original->data);
        original = original->next;
    }

    // step2: add cloneNode in btw of original list
    original = head;
    Node *clone = cloneHead;

    while (original != NULL)
    {
        Node *next = original->next;
        original->next = clone;
        original = next;

        next = clone->next;
        clone->next = original;
        clone = next;
    }

    // step3: copy random pointers
    original = head;
    while (original != NULL)
    {
        if (original->next != NULL)
        {
            original->next->arb = original->arb ? original->arb->next : original->arb;
        }
        original = original->next->next;
    }

    // step4: revert changes
    original = head;
    clone = cloneHead;

    while (original != NULL)
    {
        original->next = clone->next;
        original = original->next;

        if (original != NULL)
        {
            clone->next = original->next;
        }
        clone = clone->next;
    }

    return cloneHead;
}

// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1