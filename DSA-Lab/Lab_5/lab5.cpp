#include <iostream>
using namespace std;

class LinkedList
{
private:
    // Node represents one element of the linked list
    struct Node
    {
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node *head; // Points to the first node
    int size;   // Stores the number of elements
    bool isEmpty() { return (head == nullptr); }
    bool isValidIndex(int index)
    {
        return (index >= 0 && index < size);
    }

public:
    LinkedList();
    LinkedList(int value);
    ~LinkedList();
    void add(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index);
    void set(int index, int value);
    int getSize();
    void display();
};

class DoublyLinkedList
{
private:
    // Node stores one element and links to the next and previous nodes
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node *head; // Points to the first node
    int size;   // Stores the number of elements
    bool isEmpty() { return (head == nullptr); }
    bool isValidIndex(int index)
    {
        return (index >= 0 && index < size);
    }

public:
    DoublyLinkedList();
    DoublyLinkedList(int value);
    DoublyLinkedList(LinkedList ll);
    ~DoublyLinkedList();
    void add(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index);
    void set(int index, int value);
    int getSize();
    void display(bool reverse = false);
};

int main()
{
    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    DoublyLinkedList d(list);
    d.display();
    d.display(true);
}

// Default Constructor
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}
// Parameterized Constructor
LinkedList::LinkedList(int value)
{

    head = new Node(value);
    size = 1;
}
// Destructor
LinkedList::~LinkedList()
{
    // Delete each node one by one
    while (head)
    {
        Node *curr = head; // Save the current node
        head = head->next; // Move to the next node before deleting
        delete curr;
    }
}
// Add element at the end
void LinkedList::add(int value)
{
    Node *newNode = new Node(value);
    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        // Traverse to the last node
        while (curr->next)
        {
            curr = curr->next;
        }
        // Link the last node to the new node
        curr->next = newNode;
    }

    size++;
}
// Insert element at a specific index
void LinkedList::insert(int index, int value)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid index." << endl;
        return;
    }
    Node *newNode = new Node(value);
    if (index == 0)
    {
        // New node becomes the first node
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *curr = head;
        // Move to the node immediately before the insertion position
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        // Connect the new node between curr and the next node
        newNode->next = curr->next;
        curr->next = newNode;
    }
    size++;
}
// Remove element at a specific index

void LinkedList::remove(int index)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return;
    }
    if (index == 0)
    {
        Node *removalNode = head;
        head = head->next;  // Move head to the second node
        delete removalNode; // Delete the old first node
    }
    else
    {
        Node *curr = head;
        // Move to the node immediately before the removal position
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        Node *removalNode = curr->next;
        curr->next = removalNode->next; // Skip the node being removed
        delete removalNode;             // Delete the removed node
    }
    size--;
}
// Get element at an index

int LinkedList::get(int index)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return -1;
    }
    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return -1;
    }
    Node *curr = head;
    // Traverse to the node at the requested index
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}
// Modify element at an index
void LinkedList::set(int index, int value)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return;
    }

    Node *curr = head;
    // Traverse to the node at the requested index
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    curr->data = value;
}
// Return current number of elements
int LinkedList::getSize()
{
    return size;
}
// Display the list
void LinkedList::display()
{
    Node *curr = head;
    cout << "[";
    while (curr)
    {
        cout << curr->data;
        if (curr->next)
        {
            cout << ", ";
        }
        curr = curr->next;
    }
    cout << "]" << endl;
}

// Default Constructor
DoublyLinkedList::DoublyLinkedList()
{
    // Creates an empty list
    head = nullptr;
    size = 0;
}
// Parameterized Constructor
DoublyLinkedList::DoublyLinkedList(int value)
{
    // Creates a list containing one element
    head = new Node(value);
    size = 1;
}

DoublyLinkedList::DoublyLinkedList(LinkedList ll)
{
    // if (ll.getsize() == 0)
    head = nullptr;
    size = 0;
    Node *current = head;
    for (int i = 0; i < ll.getSize(); i++)
    {
        Node *n = new Node(ll.get(i));
        size++;
        if (i == 0)
            head = n;
        n->prev = current;

        if (i != 0)
        {
            current->next = n;
        }
        current = n;
    }
}
// Destructor
DoublyLinkedList::~DoublyLinkedList()
{
    // Deletes all dynamically allocated nodes to release memory
    while (head)
    {

        Node *curr = head; // Save the current node
        head = head->next; // Move to the next node before deleting
        delete curr;
    }
}
// Add element at the end
void DoublyLinkedList::add(int value)
{
    Node *newNode = new Node(value);
    // If the list is empty
    if (isEmpty())
    {
        head = newNode; // The new node becomes the first node
    }
    else
    {
        Node *curr = head;
        // Traverse to the last node
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode; // Link the last node to the new node
        newNode->prev = curr; // Link the new node back to the previous last node
    }
    size++;
}
// Insert element at a specific index
void DoublyLinkedList::insert(int index, int value)
{
    if (index < 0 || index > size)

    {
        cout << "Invalid index." << endl;
        return;
    }
    Node *newNode = new Node(value);
    if (index == 0)
    {
        newNode->next = head;
        if (head) // If the list was not empty
        {
            head->prev = newNode; // Update the old first node to point back to the new node
        }
        head = newNode;
    }
    else
    {
        Node *curr = head;
        // Move to the node immediately before the insertion position
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        newNode->next = curr->next; // Place the new node between curr and curr->next if (curr->next) // If a node exists after the new node
        {
            curr->next->prev = newNode; // Update its previous pointer to point to the new node
        }
        curr->next = newNode; // Connect curr to the new node

        newNode->prev = curr; // Connect the new node back to curr
    }
    size++;
}
// Remove element at a specific index
void DoublyLinkedList::remove(int index)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return;
    }
    if (index == 0)
    {
        Node *removalNode = head;
        head = head->next; // Move head to the second node
        if (head)          // If another node becomes the first node
        {
            head->prev = nullptr; // Its previous pointer must point to nullptr
        }
        delete removalNode; // Delete the old first node
    }
    else
    {
        Node *curr = head;
        // Move to the node immediately before the removal position
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        Node *removalNode = curr->next;
        curr->next = removalNode->next; // Skip the node being removed
        // If a node exists after the removed node
        if (removalNode->next)
        {
            removalNode->next->prev = curr; // Update its previous pointer
        }
        delete removalNode; // Delete the removed node
    }
    size--;
}
// Get element at an index
int DoublyLinkedList::get(int index)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return -1;
    }
    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return -1;
    }
    Node *curr = head;

    // Traverse to the node at the requested index
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}
// Modify element at an index
void DoublyLinkedList::set(int index, int value)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return;
    }
    Node *curr = head;
    // Traverse to the node at the requested index
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    curr->data = value;
}
// Return current number of elements
int DoublyLinkedList::getSize()
{
    return size;
}
// Display the list
void DoublyLinkedList::display(bool reverse)
{
    Node *curr = head;
    cout << "[";
    if (!reverse) // If reverse is false, display from head to tail
    {
        while (curr)
        {
            cout << curr->data;
            if (curr->next)
            {
                cout << ", ";
            }
            curr = curr->next;
        }
    }
    else // If reverse is true, display from tail to head
    {
        // First reach the last node
        while (curr && curr->next)
        {
            curr = curr->next;
        }
        // Traverse backward using the previous pointers
        while (curr)
        {
            cout << curr->data;
            if (curr->prev)
            {
                cout << ", ";
            }
            curr = curr->prev;
        }
    }

    cout << "]" << endl;
}
