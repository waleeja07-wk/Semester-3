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

    void push(int val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
    }

    int pop()
    {
        int x = top->val;
        top = top->next;
        return x;
    }

    int Top()
    {
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