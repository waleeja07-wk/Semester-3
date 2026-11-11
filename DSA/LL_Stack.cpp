#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void push(int val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node *temp = top; // we use this temp to delete the node permenantly, to avoid memory leaks
        int x = temp->val;
        top = top->next;
        delete temp;
        return x;
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        return top->val;
    }
};

int main()
{
    Stack s1;
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(56);
    cout << s1.pop() << endl;
    cout << s1.Top() << endl;
}