#include <iostream>
using namespace std;
class ArrayList
{
private:
    int *arr;
    int size;
    int capacity;
    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size == capacity); }
    bool isValidIndex(int index)
    {
        return (index >= 0 && index < size);
    }

public:
    ArrayList();
    ArrayList(int value);
    ~ArrayList();
    void add(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index);
    void set(int index, int value);
    int getSize();
    void rearrangeList();
    void display();
};
int main()
{
    ArrayList list;
    list.add(5);
    list.add(2);
    list.add(9);
    list.add(4);
    list.add(7);
    list.add(6);
    list.add(1);
    list.add(3);
    list.add(8);
    list.display();
    list.rearrangeList();
    list.display();
    // list.insert(1, 15);
    // list.display();
    // list.remove(2);
    // list.display();
    // list.set(1, 70);
    // list.display();

    cout << "Element at index 1: " << list.get(1) << endl;
    cout << "Size: " << list.getSize() << endl;
}
// Default Constructor
ArrayList::ArrayList()
{
    capacity = 10;
    arr = new int[capacity];
    size = 0;
}
// Parameterized Constructor
ArrayList::ArrayList(int value)
{
    capacity = 10;
    arr = new int[capacity];
    *arr = value;
    size = 1;
}
// Destructor
ArrayList::~ArrayList()
{
    delete[] arr;
}
// Add element at the end
void ArrayList::add(int value)
{
    if (isFull())
    {
        cout << "List is full." << endl;
        return;
    }
    *(arr + size) = value;

    size++;
}
// Insert element at a specific index
void ArrayList::insert(int index, int value)
{
    if (isFull())
    {
        cout << "List is full." << endl;
        return;
    }
    if (index < 0 || index > size)
    {
        cout << "Invalid index." << endl;
        return;
    }
    // Shift elements to the right
    for (int i = size; i > index; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + index) = value;
    size++;
}
// Remove element at a specific index
void ArrayList::remove(int index)
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
    // Shift elements to the left
    for (int i = index; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    size--;
}
// Get element at an index
int ArrayList::get(int index)
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
    return *(arr + index);
}
// Modify element at an index
void ArrayList::set(int index, int value)
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
    *(arr + index) = value;
}
// Return current number of elements
int ArrayList::getSize()
{
    return size;
}

void ArrayList::rearrangeList(){
    int count = 0;
    for(int i=0; i<size; i++){
        if(*(arr+i)%2==0){
            insert(count, *(arr+i));
            remove(i+1);
            count++;
        }
        
    }
    count=0;
    int j=1;
    for(int i=0; i<size; i+=2){
        if(*(arr+i)%2!=0){
            
            insert(count+j, *(arr+i));
            remove(i+1);
            count++;
            j++;
        }
        
    }
}

// Display the list
void ArrayList::display()
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i);
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}