#include <iostream>

using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    void push(int element)
    {
        if (this->size - this->top > 1)
            this->arr[++this->top] = element;
        else
            cout << "Stack Overflow" << endl;
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
            this->top--;
    }

    int peek()
    {
        return this->arr[this->top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        for (int i = this->top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << "TOP = " << s.peek() << endl;
    s.display();

    s.pop();
    cout << "AFTER POPPING ELEMENT " << endl;
    cout << "TOP = " << s.peek() << endl;
    s.display();

    return 0;
}