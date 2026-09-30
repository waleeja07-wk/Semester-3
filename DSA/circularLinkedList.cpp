#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(int v){
        val = v;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node *head;
    int length;
public:
    LinkedList(){
        head = nullptr;
        length = 0;
    }

    bool isValidPos(int pos){   return (pos>0 && pos<=length+1);  }
    bool isEmpty(){   return (length==0);  }
    

    void insert(int v, int pos){
        if(!isValidPos(pos)){
            return;
        }

        Node *n = new Node(v);
        if(pos==1){
            if(head==nullptr){
            head = n;
            head->next = head;
            }
            else{
                n->next = head;
                head = n;
            }
        }
        else{
            Node *current = head;
            for(int i=1; i<(pos-1); i++){
                current = current->next;
            }
            n->next = current->next;
            current->next = n;
        }

        length++;
    }

    void remove(int pos){
        if(isEmpty()){
            return;
        }

        if(!isValidPos(pos)){
            return;
        }

        Node *current = head;
        if(pos==1){
            head = head->next;
            delete current;
        }

        else{
            for(int i=1; i<(pos-1); i++){
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        length--;
    }

    int get(int pos){
        if(isEmpty()){
            return -1;
        }

        if(!isValidPos(pos)){
            return -1;
        }

        Node *current = head;
        for(int i=1; i<pos; i++){
            current = current->next;
        }
        return current->val;
    }

    void update(int v, int pos){
        if(isEmpty()){
            return;
        }

        if(!isValidPos(pos)){
            return;
        }

        Node *current = head;
        for(int i=1; i<pos; i++){
            current = current->next;
        }

        current->val= v;
    }

    int find(int val){
        if(isEmpty()){
            return -1;
        }

        Node *current = head;
        for(int i=1; i<=length; i++){
            if(current->val == val){
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    void removeByVal(int val){
        int pos = find(val);
        if(pos!=-1){
            remove(pos);
        }
    }

    void clear(){
        while(head!=nullptr){
            remove(1);
        }
    }

    bool isPalindrome(){
        Node *current = head;
        Node *tail = head;
        Node *n = head;
        while(tail->next != head){
            tail = tail->next;
        }

        while(current!=tail){
            if(current->val!=tail->val){
                return false;
            }

            if(current->next == tail){   // <-- add this: even-length base case
                break;
            }
                current= current->next;
                n=head;
                while(n->next!=tail){
                    n = n->next;
                }
                tail = n;
        }
        return true;
    }

    void copy(LinkedList &other){
        clear();
        for(int i=1; i<other.length; i++){
            insert(other.get(i), i);
        }
    }

    void changePos(int currPos, int newPos){
        if(isEmpty()){
            return;
        }

        if(!isValidPos(currPos) || !isValidPos(newPos)){
            return;
        }

        if(currPos==newPos) return;

        Node *current = head;
        if(currPos==1){
            head = head-> next;
            current->next = nullptr;

            Node *n = new Node(current->val);
            current = head;

            for(int i=1; i<newPos-1; i++){
                current = current->next;
            }

            n->next = current->next;
            current->next = n;
        }

        else if(newPos==1){
            for(int i=1; i<currPos-1; i++){
            current = current->next;
          }
          Node *temp = current->next;
          current->next = temp->next;

          temp->next = head;
          head = temp;
        }

        else{
          for(int i=1; i<currPos-1; i++){
            current = current->next;
          }
          Node *temp = current->next;
          current->next = temp->next;
          temp->next = nullptr;

          current = head;

          for(int i=1; i<newPos-1; i++){
            current = current->next;
          }

          temp->next = current->next;
          current->next = temp;

        }
    }

    // void SwapNodes(Node n1, Node n2){
    //     if(isEmpty()){
    //         return;
    //     }
        
        
    // }

    // ~LinkedList(){
        
    // }

    void display(){

        Node *current = head;
        for(int i=1; i<=length; i++){
            cout<<current->val<<" ";
            current = current -> next;
        }
        cout<<endl;
    }

};

int main(){
    LinkedList ll;

    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(1, 4);
    ll.display();
    cout<<ll.isPalindrome()<<endl;
    // ll.changePos(4,2);
    // ll.display();
    
    
}