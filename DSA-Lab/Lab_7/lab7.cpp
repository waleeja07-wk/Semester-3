
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
using namespace std;
class Stack
{
private:
    struct Node
    {
        string val;
        Node *next;
        Node(string v) : val(v), next(nullptr) {}
    };

    Node *top;
    int size;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    ~Stack()
    {
        while (top)
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(string x)
    {
        Node *n = new Node(x);
        n->next = top;
        top = n;
        size++;
    }

    string pop()
    {
        if (!top)
        {
            throw runtime_error("Stack is empty!");
        }

        Node *curr = top;
        string val = curr->val;
        top = top->next;
        delete curr;
        size--;
        return val;
    }

    string Top()
    {
        if (!top)
        {
            throw runtime_error("Stack is empty!");
        }
        return top->val;
    }
};
class Queue
{
private:
    struct Node
    {
        string val;
        Node *next;
        Node(string v) : val(v), next(nullptr) {}
    };

    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = rear = nullptr;
        size = 0;
    }

    ~Queue()
    {
        while (front)
        {
            dequeue();
        }
    }

    void enqueue(string val)
    {
        Node *n = new Node(val);
        if (!rear)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
        size++;
    }

    void dequeue()
    {
        if (!front)
        {
            throw runtime_error("Queue is empty!");
        }
        Node *temp = front;
        front = front->next;
        if (!front)
        {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    string peek()
    {
        if (!front)
        {
            throw runtime_error("Queue is empty!");
        }
        return front->val;
    }

    string winner(const list<string> &l, int k)
    {
        if (l.empty() || k < 1)
        {
            throw invalid_argument("Need a non-empty list and k >= 1");
        }

        while (front)
        {
            dequeue();
        }

        for (string x : l)
        {
            enqueue(x);
        }

        while (size != 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                string val = peek();
                dequeue();
                enqueue(val);
            }
            cout << "ELIMINATED: " << front->val << endl;
            dequeue();
        }
        return front->val;
    }

    int selectMeal(Stack &s)
    {
        int skip = 0;
        while (size != 0 && !s.isEmpty() && skip < size)
        {

            if (peek() == s.Top())
            {
                dequeue();
                s.pop();
                skip = 0;
            }

            else
            {
                string curr = peek();
                dequeue();
                enqueue(curr);
                skip++;
            }
        }
        return size;
    }
};

int main()
{
    // list<string> l1 = {"Ali", "Ahmed", "Khalid", "Usman", "Farhan"};
    // int k = 3;

    // Queue q1;
    // string winner = q1.winner(l1, k);
    // cout << "WINNER: " << winner << endl;

    Queue q2;
    q2.enqueue("0");
    q2.enqueue("1");
    q2.enqueue("1");

    Stack s;
    s.push("1");
    s.push("0");
    s.push("0");

    cout << "Unable to eat: " << q2.selectMeal(s) << endl; 
}