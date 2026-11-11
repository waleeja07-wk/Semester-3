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

class Queue
{
private:
    Node *front;
    Node *rear;
    int noOfElements;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        noOfElements = 0;
    }

    bool isEmpty()
    {
        return noOfElements == 0;
    }

    void enqueue(int v)
    {
        Node *n = new Node(v);
        if (isEmpty())
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }

        noOfElements++;
    }

    int dequeue()
    {
        Node *temp = front;
        int val = temp->val;
        front = front->next;
        if (front == nullptr)
            rear == nullptr;
        delete temp;
        noOfElements--;
        return val;
    }

    int peek()
    {
        return front->val;
    }
};

int main()
{
    Queue q;
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(4);
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
}