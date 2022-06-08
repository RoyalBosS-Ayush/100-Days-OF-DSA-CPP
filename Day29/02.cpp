#include <iostream>

using namespace std;

class Stack
{
public:
    int data;
    Stack *next;

    Stack(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void push(Stack *&head, int element)
{
    Stack *s = new Stack(element);
    if (head == NULL)
    {
        head = s;
    }
    else
    {
        s->next = head;
        head = s;
    }
}

void pop(Stack *&head)
{

    if (head == NULL)
        return;

    Stack *next = head->next;
    head->next = NULL;
    delete head;
    head = next;
}

int peek(Stack *&head)
{
    return head->data;
}

bool isEmpty(Stack *&head)
{
    return head == NULL;
}

void display(Stack *&head)
{
    Stack *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Stack *HEAD = NULL;

    push(HEAD, 1);
    push(HEAD, 2);
    push(HEAD, 3);
    push(HEAD, 4);

    cout << "TOP = " << peek(HEAD) << endl;
    display(HEAD);

    pop(HEAD);
    cout << "AFTER POPPING ELEMENT " << endl;
    cout << "TOP = " << peek(HEAD) << endl;
    display(HEAD);

    return 0;
}