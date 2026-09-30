#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int v){
        val = v;
        next = nullptr;
        prev = nullptr;
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
            n->next = head;
            if(head !=nullptr) head->prev = n;
            head = n;
        }
        else{
            Node *current = head;
            for(int i=1; i<(pos-1); i++){
                current = current->next;
            }
            n->next = current->next;
            n->prev=current;
            if(current->next!=nullptr){
                current->next->prev = n;
            }
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
            if(head!=nullptr){
                head->prev = nullptr;
            }
            delete current;
        }

        else{
            for(int i=1; i<(pos-1); i++){
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            if(temp->next!=nullptr){
                temp->next->prev = current;
            }
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
            head->prev = current->prev;
            current->next = nullptr;

            Node *n = new Node(current->val);
            current = head;

            for(int i=1; i<newPos-1; i++){
                current = current->next;
            }

            n->next = current->next;
            n->prev = current;
            current->next = n;
        }

        else if(newPos==1){
            for(int i=1; i<currPos-1; i++){
            current = current->next;
          }
          Node *temp = current->next;
          current->next = temp->next;
          temp->next->prev = temp->prev;

          temp->next = head;
          temp->prev = head->prev;
          head->prev = temp;
          head = temp;
        }

        else{
          for(int i=1; i<currPos-1; i++){
            current = current->next;
          }
          Node *temp = current->next;
          current->next = temp->next;
          temp->next->prev = temp->prev;
          temp->next = temp->prev = nullptr;

          current = head;

          for(int i=1; i<newPos-1; i++){
            current = current->next;
          }

          temp->next = current->next;
          temp->prev = current;
          if(current->next!=nullptr) current->next->prev = temp;
          current->next = temp;

        }
    }


    // void reverseList(){
    //     if(isEmpty()){
    //         return;
    //     }

    //     Node *current= head;
    //     Node *temp = current;

    //     for(int i=0; i<length; i++){
    //         temp = temp->next;
    //     }

    //     while(current!=temp){
    //         changePos()

    //         // current = current->next;
    //         // temp = temp->prev;
    //     }
    // }

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

    ll.insert(8, 1);
    ll.insert(6, 2);
    ll.insert(5, 3);
    ll.insert(4, 4);
    ll.display();
    ll.changePos(3,4);
    ll.display();
    // ll.reverseList();
    // ll.display();
}