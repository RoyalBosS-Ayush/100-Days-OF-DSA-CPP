#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        if (this->prev != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
    }
};

Node *TAIL = NULL;

void insertNode(int element, int data)
{
    if (TAIL == NULL)
    {
        Node *temp = new Node(data);
        TAIL = temp;
        TAIL->next = temp;
        TAIL->prev = temp;
        return;
    }

    Node *temp = new Node(data);
    Node *curr = TAIL;
    do
    {
        if (curr->data == element)
        {
            temp->next = curr->next;
            temp->prev = curr->next->prev;
            curr->next->prev = temp;
            curr->next = temp;
            break;
        }
        curr = curr->next;
    } while (curr != TAIL);
}

void deleteNode(int element)
{
    Node *temp = TAIL;
    do
    {
        if (temp->data == element)
        {
            if (temp->next == temp) // single element
            {
                TAIL = NULL;
                temp->next = NULL;
                temp->prev = NULL;
                delete temp;
            }
            else
            {
                if (temp == TAIL)
                    TAIL = TAIL->next;
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                temp->next = NULL;
                temp->prev = NULL;
                delete temp;
            }
            break;
        }
        temp = temp->next;
    } while (temp != TAIL);
}

void print()
{
    Node *temp = TAIL;
    if (TAIL == NULL)
        return;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != TAIL);
    cout << endl;
}

void reversePrint()
{
    if (TAIL == NULL)
        return;

    Node *temp = TAIL->prev;
    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != TAIL->prev);
    cout << endl;
}

int main()
{
    insertNode(1, 1); // 1
    insertNode(1, 2); // 1 2
    insertNode(1, 3); // 1 3 2
    insertNode(2, 4); // 1 3 2 4

    print();
    reversePrint();

    deleteNode(1); // 3 2 4
    print();
    reversePrint();

    deleteNode(2); // 3 4
    print();
    reversePrint();

    deleteNode(3); // 4
    print();
    reversePrint();

    deleteNode(4); //
    print();
    reversePrint();

    return 0;
}