#include <iostream>
using namespace std;
class LinkedList
{
private:
// Node represents one element of the linked list
    struct Node
    {
        char data;
        Node *next;
        Node(char value) : data(value), next(nullptr) {}
    };
    Node *head; // Points to the first node
    Node *tail;
    int size; // Stores the number of elements
    bool isEmpty() { return (head == nullptr); }
    bool isValidIndex(int index) { return (index >= 0 && index < size);
}
public:
    LinkedList();
    LinkedList(char value);
    ~LinkedList();
    void add(char value);
    void insert(int index, char value);
    void remove(int index);
    char get(int index);
    void set(int index, char value);
    int getSize();
    void replaceHead();
    void clear();
    void removeDuplicates();
    void display();
    friend void mergeLL(LinkedList l1, LinkedList L);
};

void mergeLL(LinkedList ll1, LinkedList ll2){
    
    Node *curr = ll1->head;
    for(int i=0; i<ll1.getSize(); i++){
       
    }
}
int main()
{
    LinkedList list1;
    list1.add(1);
    list1.add(3);
    list1.add(5);

    LinkedList list2;
    list2.add(2);
    list2.add(4);
    list2.add(6);

    // cout<<list.get(list.getSize()-1)<<endl;
    // list.display();
    // list.insert(1, 'D');
    // list.display();
    // list.remove(2);
    // list.display();
    // list.set(1, 'E');
    // list.display();
    // list.replaceHead();
    // list.display();
    // cout << "Element at index 1: " << list.get(1) << endl;
    // cout << "Size: " << list.getSize() << endl;
    // list.clear();
    // list.display();
}
// Default Constructor
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
// Parameterized Constructor
LinkedList::LinkedList(char value)
{
    head = new Node(value);
    tail = head;
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
    tail = head;
}
// Add element at the end
void LinkedList::add(char value)
{
    Node *newNode = new Node(value);
    if (isEmpty())
    {
        head = tail = newNode;
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
        tail = newNode;
    }
    size++;
}
// Insert element at a specific index
void LinkedList::insert(int index, char value)
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
    if(newNode->next == nullptr){
            tail = newNode;
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
        if(index==size-1){
            removalNode->next = nullptr;
        }
        else{
            head = head->next; // Move head to the second node
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
        delete removalNode; // Delete the removed node
    }
    size--;
}
// Get element at an index
char LinkedList::get(int index)
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
    if(index==size-1){
        return tail->data;
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
void LinkedList::set(int index, char value)
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

void LinkedList::replaceHead(){
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *curr = head;
    Node *temp =  tail;

    for(int i=1; i<size-1; i++){
        curr = curr->next;
    }

    curr->next = temp->next;
    temp->next = head;
    head = temp;
    tail = curr;
}

// void LinkedList::removeDuplicates(){
//     if(isEmpty()){
//         return;
//     }

//     Node *curr  = head;
//     while(curr->next){
//         if()
//     }
// }

// void LinkedList::clear(){
   

// }
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
