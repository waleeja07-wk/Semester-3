#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int cap;
    int top;

public:
    stack(int s)
    {
        arr = new int[s];
        cap = s;
        top = -1;
    }

    ~stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (cap == (top + 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "OVERFLOW" << endl;
            return;
        }

        top++;
        arr[top] = val;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        int temp = arr[top];
        top--;
        return temp;
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        return arr[top];
    }

    void display()
    {
        int t = top;
        while (t != -1)
        {
            cout << arr[t] << " ";
            t--;
        }
        cout << endl;
    }
};

int main()
{
    stack s(2);
    s.push(3);
    s.push(1);
    s.display();
    s.pop();
    s.display();
}