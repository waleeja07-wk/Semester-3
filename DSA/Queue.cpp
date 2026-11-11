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
        arr = new int[s];
        size = s;
        front = 0;
        rear = -1;
        noOfElements = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty() { return noOfElements == 0; }
    bool isFull() { return noOfElements == size; }

    void enqueue(int v)
    {
        if (isFull())
            throw std::runtime_error("Queue is full");
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

    int dequeue()
    {
        if (isEmpty())
            throw std::runtime_error("Queue is empty");
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

    int peek()
    {
        if (isEmpty())
            throw runtime_error("Queue is empty!");
        return arr[front];
    }
};

int main()
{
    Queue q(3);
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}