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
    int size;
    int noOfElements;

public:
    Queue(int s)
    {

        size = s;
        front = nullptr;
        rear = nullptr;
        noOfElements = 0;
    }

    void enque(int v)
    {
        Node *n = new Node(v);
        if (rear->next == nullptr)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        n->next = rear;
        rear = n;
        noOfElements++;
    }

    int deque()
    {
        int val = front->val;
        if (front->next == nullptr)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        noOfElements--;
        return val;
    }
};

int main()
{
    Queue q(3);
    q.enque(3);
    q.enque(8);
    q.enque(4);
    cout << q.deque();
    cout << q.deque();
    cout << q.deque();
}