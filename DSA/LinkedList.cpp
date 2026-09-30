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

class LinkedList
{
private:
    Node *head;
    int length;

public:
    LinkedList()
    {
        head = nullptr;
        length = 0;
    }

    bool isValidPos(int pos) { return (pos > 0 && pos <= length + 1); }
    bool isEmpty() { return (length == 0); }

    void insert(int v, int pos)
    {
        if (!isValidPos(pos))
        {
            return;
        }

        Node *n = new Node(v);
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *current = head;
            for (int i = 1; i < (pos - 1); i++)
            {
                current = current->next;
            }
            n->next = current->next;
            current->next = n;
        }

        length++;
    }

    void remove(int pos)
    {
        if (isEmpty())
        {
            return;
        }

        if (!isValidPos(pos))
        {
            return;
        }

        Node *current = head;
        if (pos == 1)
        {
            head = head->next;
            delete current;
        }

        else
        {
            for (int i = 1; i < (pos - 1); i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        length--;
    }

    int get(int pos)
    {
        if (isEmpty())
        {
            return -1;
        }

        if (!isValidPos(pos))
        {
            return -1;
        }

        Node *current = head;
        for (int i = 1; i < pos; i++)
        {
            current = current->next;
        }
        return current->val;
    }

    void update(int v, int pos)
    {
        if (isEmpty())
        {
            return;
        }

        if (!isValidPos(pos))
        {
            return;
        }

        Node *current = head;
        for (int i = 1; i < pos; i++)
        {
            current = current->next;
        }

        current->val = v;
    }

    int find(int val)
    {
        if (isEmpty())
        {
            return -1;
        }

        Node *current = head;
        for (int i = 1; i <= length; i++)
        {
            if (current->val == val)
            {
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    void removeByVal(int val)
    {
        int pos = find(val);
        if (pos != -1)
        {
            remove(pos);
        }
    }

    void clear()
    {
        while (head != nullptr)
        {
            remove(1);
        }
    }

    void copy(LinkedList &other)
    {
        clear();
        for (int i = 1; i < other.length; i++)
        {
            insert(other.get(i), i);
        }
    }

    void changePos(int currPos, int newPos)
    {
        if (isEmpty())
        {
            return;
        }

        if (!isValidPos(currPos) || !isValidPos(newPos))
        {
            return;
        }

        if (currPos == newPos)
            return;

        Node *current = head;
        if (currPos == 1)
        {
            head = head->next;
            current->next = nullptr;

            Node *n = new Node(current->val);
            current = head;

            for (int i = 1; i < newPos - 1; i++)
            {
                current = current->next;
            }

            n->next = current->next;
            current->next = n;
        }

        else if (newPos == 1)
        {
            for (int i = 1; i < currPos - 1; i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;

            temp->next = head;
            head = temp;
        }

        else
        {
            for (int i = 1; i < currPos - 1; i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            temp->next = nullptr;

            current = head;

            for (int i = 1; i < newPos - 1; i++)
            {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
        }
    }

    void swapNodes(int pos1, int pos2)
    {
        if (isEmpty())
        {
            return;
        }

        if (!isValidPos(pos1) || !isValidPos(pos2))
        {
            return;
        }

        if (pos1 == pos2)
            return;

        if (pos1 > pos2)
            swap(pos1, pos2);

        Node *current1 = head;
        Node *temp1 = head;

        if (pos1 == 1)
        {

            head = head->next;
            temp1->next = nullptr;
            current1 = head;
        }

        else
        {

            for (int i = 1; i < pos1 - 1; i++)
            {
                current1 = current1->next;
            }
            temp1 = current1->next;

            current1->next = temp1->next;
            temp1->next = nullptr;
        }

        Node *current2 = head;
        Node *temp2 = head;

        if (pos1 == 1 && pos2 == 2)
        {
            temp2 = head;
            head = head->next;
            temp2->next = nullptr;
        }

        else
        {
            for (int i = 1; i < pos2 - 2; i++)
            {
                current2 = current2->next;
            }
            temp2 = current2->next;

            current2->next = temp2->next;
            temp2->next = nullptr;
        }

        current1 = head;
        for (int i = 1; i < pos1 - 1; i++)
        {
            current1 = current1->next;
        }

        temp1->next = current1->next;
        current1->next = temp1;

        current2 = head;
        for (int i = 1; i < pos2 - 2; i++)
        {
            current2 = current2->next;
        }

        temp2->next = current2->next;
        current2->next = temp2;
    }

    void reverseList()
    {
        if (isEmpty())
        {
            return;
        }

        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void removeDuplicates()
    {
        if (isEmpty())
        {
            return;
        }

        Node *current = head;

        while (current != nullptr)
        {
            Node *runner = current;

            while (runner->next != nullptr)
            {
                if (runner->next->val == current->val)
                {
                    Node *duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                    length--;
                }
                else
                {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    bool isPalindrome()
    {
        if (isEmpty())
        {
            return true;
        }

        int *arr = new int[length];
        Node *current = head;

        for (int i = 0; i < length; i++)
        {
            arr[i] = current->val;
            current = current->next;
        }

        int left = 0;
        int right = length - 1;
        bool result = true;

        while (left < right)
        {
            if (arr[left] != arr[right])
            {
                result = false;
                break;
            }
            left++;
            right--;
        }

        delete[] arr;
        return result;
    }

    void reverseKnodes(int k)
    {
        Node *current = head;
        Node *temp = head;
        while(current->next != nullptr){
            for(int i=0; i<k-1; i++){
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;

            current = current->next;
        }
    }
    // ~LinkedList(){

    // }

    void display()
    {

        Node *current = head;
        for (int i = 1; i <= length; i++)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll;

    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(4, 4);
    ll.insert(5,5);
    ll.display();
    ll.reverseKnodes(2);
    ll.display();
    // ll.changePos(1, 3);
    // ll.display();
    // ll.changePos(3, 4);
    // ll.display();
    // ll.swapNodes(3, 4);
    // ll.display();
}