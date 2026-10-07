#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;
    int noOfElements;

public:
    Queue(int s)
    {
        int *arr = new int[s];
        size = s;
        front = 0;
        rear = -1;
        noOfElements = 0;
    }

    void enque(int v)
    {
        if (rear == (size - 1))
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = v;
        noOfElements++;
    }

    int deque()
    {
        int val = arr[front];
        if (front == (size - 1))
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