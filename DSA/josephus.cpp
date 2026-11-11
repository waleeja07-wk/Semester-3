#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Cicular Linked List Class
template <typename T>
class CirclyLinkedList {
    struct Node {
        T data;
        Node* next;
        Node(T data): data(data), next(nullptr) {}
    };
    Node* head;
    int len;
public:
    CirclyLinkedList(): head(nullptr), len(0) {}

    void push_back(T data) {
        Node* newNode=new Node(data);
        if(!head) { head=newNode; head->next=head; }
        else {
            Node* prev=head;
            while(prev->next!=head) prev=prev->next;
            newNode->next=head;
            prev->next=newNode;
        }
        len++;
    }
    void remove(int pos) {
        if(!head) throw std::underflow_error("List is empty!\n");
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        Node* target;
        if(pos==1) {
            target=head;
            if(head->next==head) head=nullptr;
            else {
                Node* prev=head;
                while(prev->next!=head) prev=prev->next;
                head=head->next;
                prev->next=head;
            }
        } else if(pos==len) {
            if(head->next==head) { target=head; head=nullptr; }
            else {
                Node* prev=head;
                while(prev->next->next!=head) prev=prev->next;
                target=prev->next;
                prev->next=head;
            }
        } else {
            Node* prev=head;
            for(int i=1;i<pos-1;i++) prev=prev->next;
            target=prev->next;
            prev->next=target->next;
        }
        delete target;
        len--;
    }

    // Josephus Function
    T josephus(T* values, int size, int skip) {
        // Check if size is less than 1 (Throw error)
        if(size<1) throw std::invalid_argument("Invalid argument!");
        // Check if skip is less than 1 (Throw error)
        if(skip<1) throw std::invalid_argument("Invalid argument!");
        // Clear List if previous values exist
        clear();
        // Fill new values
        for(int i=0;i<size;i++) push_back(*(values+i));
        // Applying Josephus Elimination
        int pos=1;
        while(len > 1) {
            pos=(pos+skip-2)%len+1; // Wrap around formula
            remove(pos);
        }
        return head->data;
    }

    void clear() { while(head) remove(1); }
    bool empty() const { return !len; }

    ~CirclyLinkedList() { clear(); }
};

// Main function
int main() {
    CirclyLinkedList<string> cll;
    string vals[]={"Areeba","Areej","Awais","Easha","Hasnain","Shayan","Talha","Waleeja"};
    int skip = 3;
    string lead = cll.josephus(vals, sizeof(vals)/sizeof(*vals), skip);
    cout  << "Answer: " << lead << '\n';
    return 0;
}