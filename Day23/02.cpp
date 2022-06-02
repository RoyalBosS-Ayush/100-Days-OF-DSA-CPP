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
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
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
        return;
    }

    Node *temp = new Node(data);
    Node *curr = TAIL;
    do
    {
        if (curr->data == element)
        {
            temp->next = curr->next;
            curr->next = temp;
            break;
        }
        curr = curr->next;
    } while (curr != TAIL);
}

void deleteNode(int element)
{
    Node *HEAD = TAIL->next;
    Node *prev = TAIL;
    Node *temp = TAIL->next;
    do
    {
        if (temp->data == element)
        {
            if (temp->next == temp) // single element
            {
                TAIL = NULL;
                temp->next = NULL;
                delete temp;
            }
            else
            {
                if (temp == TAIL)
                    TAIL = TAIL->next;
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != HEAD);
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

int main()
{
    insertNode(1, 1); // 1
    insertNode(1, 2); // 1 2
    insertNode(1, 3); // 1 3 2
    insertNode(2, 4); // 1 3 2 4

    print();

    deleteNode(1); // 3 2 4
    print();

    deleteNode(2); // 3 4
    print();

    deleteNode(3); // 4
    print();

    deleteNode(4); //
    print();

    return 0;
}