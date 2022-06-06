#include <iostream>
#include <vector>

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

bool isPal(vector<int> arr)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        if (arr[start++] != arr[end--])
            return false;
    }
    return true;
}

bool isPalindrome(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return isPal(arr);
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