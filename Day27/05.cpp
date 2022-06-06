#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    struct Node *reverse(struct Node *head)
    {
        struct Node *curr = head;
        struct Node *prev = NULL;
        struct Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(struct Node *&head, struct Node *&tail, int data)
    {
        struct Node *temp = new Node(data);
        if (tail == NULL)
        {
            tail = temp;
            head = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    // struct Node *add(struct Node *first, struct Node *second)
    // {
    //     Node *head = NULL;
    //     Node *tail = head;
    //     int carry = 0;

    //     while (first != NULL && second != NULL)
    //     {
    //         int sum = first->data + second->data + carry;
    //         int digit = sum % 10;
    //         carry = sum / 10;
    //         insertAtTail(head, tail, digit);
    //         first = first->next;
    //         second = second->next;
    //     }

    //     while (first != NULL)
    //     {
    //         int sum = first->data + carry;
    //         int digit = sum % 10;
    //         carry = sum / 10;
    //         insertAtTail(head, tail, digit);
    //         first = first->next;
    //     }

    //     while (second != NULL)
    //     {
    //         int sum = second->data + carry;
    //         int digit = sum % 10;
    //         carry = sum / 10;
    //         insertAtTail(head, tail, digit);
    //         second = second->next;
    //     }

    //     if (carry)
    //     {
    //         insertAtTail(head, tail, carry);
    //     }

    //     return head;
    // }

    struct Node *add(struct Node *first, struct Node *second)
    {
        Node *head = NULL;
        Node *tail = head;
        int carry = 0;

        while (first != NULL || second != NULL || carry != 0)
        {
            if (first != NULL)
            {
                carry += first->data;
                first = first->next;
            }
            if (second != NULL)
            {
                carry += second->data;
                second = second->next;
            }

            int digit = carry % 10;
            carry /= 10;

            insertAtTail(head, tail, digit);
        }

        return head;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);

        struct Node *ans = add(first, second);
        ans = reverse(ans);
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1