#include <iostream>
using namespace std;

/* Section 1: Data Structures */
/* 1. Convert the Existing Implementation to Store Strings */

// class ArrayList
// {
// private:
//     string *arr;
//     int size;
//     int capacity;
//     bool isEmpty() { return (size == 0); }
//     bool isFull() { return (size == capacity); }
//     bool isHalf() { return (size < (capacity/2)); }
//     bool isValidIndex(int index) { return (index >= 0 && index < size);}

// public:
//     ArrayList();
//     ArrayList(int capacity);
//     ~ArrayList();
//     void add(string value);
//     void insert(int index, string value);
//     void remove(int index);
//     string get(int index);
//     int getSize();
//     void remove(string value);
//     bool search(string value);
//     int retrieve(string value);
//     void replace(string oldVal, string newVal);
//     void clear();
//     void sort(bool flag);
//     void reverse();
//     void resize();
//     void display();
// };

// int main(){

// ArrayList list;
//     list.add("10");
//     list.add("20");
//     list.add("30");
//     list.insert(1, "40");
//     list.remove("20");
//     list.display();
//     list.reverse();
//     list.display();
//     cout << "Element at index 1: " << list.get(1) << endl;
//     cout << "Size: " << list.getSize() << endl;
//     cout<<list.search("30")<<endl;
//     cout<<"Value at Index: "<<list.retrieve("40")<<endl;
//     list.replace("10", "15");
//     list.display();
//     list.sort(true);
//     list.display();
//     list.sort(false);
//     list.display();
//     list.clear();
//     list.display();
//     cout<< "Size: "<<list.getSize()<<endl;

// }

// // Default Constructor
// ArrayList::ArrayList(){
//     capacity = 10;
//     size = 0;
//     arr = new string[capacity];
// }

// // Parameterized Constructor
// ArrayList::ArrayList(int capacity){
// // If provided capacity is invalid
//     if (capacity <= 0){
//         capacity = 10;
//     }
//     this->capacity = capacity;
//     size = 0;
//     arr = new string[capacity];
// }

// // Destructor
// ArrayList::~ArrayList(){
//     delete[] arr;
// }

// // Add element at the end
// void ArrayList::add(string value){
//     if (isFull()){
//         resize();
//     }
//     *(arr + size) = value;
//     size++;
// }

// // Insert element at a specific index
// void ArrayList::insert(int index, string value){
//     if (isFull()){
//         resize();
//     }

//     if (!isValidIndex(index)){
//         cout << "Invalid index." << endl;
//         return;
//     }

// // Shift elements to the right
//     for (int i = size; i > index; i--){
//         *(arr + i) = *(arr + i - 1);
//     }
//     *(arr + index) = value;
//     size++;
// }

// // Remove element at a specific index
// void ArrayList::remove(int index){
//     if (isEmpty()){
//         cout << "List is empty." << endl;
//         return;
//     }

//     if (!isValidIndex(index)){
//         cout << "Invalid index." << endl;
//         return;
//     }

// // Shift elements to the left
//     for (int i = index; i < size - 1; i++){
//         *(arr + i) = *(arr + i + 1);
//     }
//     size--;

//     if (isHalf()){
//         resize();
//     }
// }

// // Get element at an index
// string ArrayList::get(int index){
//     if (isEmpty()){
//         cout << "List is empty." << endl;
//         return " ";
//     }

//     if (!isValidIndex(index)){
//         cout << "Invalid index." << endl;
//         return " ";
//     }
//     return *(arr + index);
// }

// // Return current number of elements
// int ArrayList::getSize(){
//     return size;
// }

// // Display the list
// void ArrayList::display()
// {
//     cout << "[";
//     for (int i = 0; i < size; i++){
//         cout << *(arr + i);
//         if (i < size - 1){
//             cout << ", ";
//         }
//     }
//     cout << "]" << endl;
// }

// // Remove by Value
// void ArrayList::remove(string value){
//     if(isEmpty()){
//         cout<<"LIST IS EMPTY"<<endl;
//         return;
//     }

//     int pos = retrieve(value);
//     if(pos == -1){
//         cout<<"value not found"<<endl;
//         return;
//     }

//     remove(pos);
// }

// // Search a value in list
// bool ArrayList::search(string value){
//     if(isEmpty()){
//         cout<<"LIST IS EMPTY"<<endl;
//         return 0;
//     }

//     for(int i=0; i<size; i++){
//         if(*(arr+i)==value){
//             return true;
//         }
//     }

//     return false;
// }

// // Return the index of a specific value
// int ArrayList::retrieve(string value){
//     if(isEmpty()){
//         cout<<"LIST IS EMPTY"<<endl;
//         return -1;
//     }

//     for(int i=0; i<size; i++){
//         if(*(arr+i)==value){
//             return i;
//         }
//     }

//     return -1;
// }

// // Update old value with new one
// void ArrayList::replace(string oldVal, string newVal){
//     if(isEmpty()){
//         cout<<"LIST IS EMPTY"<<endl;
//         return;
//     }

//     if (oldVal == newVal) return;

//     int pos;
//     while(((pos = (retrieve(oldVal)))!= -1)){
//         *(arr+pos)=newVal;
//     }
// }

// // delete all values of string
// void ArrayList::clear(){
//     size = 0;
// }

// // Sort the List in ascending or descending order
// void ArrayList::sort(bool flag){

//     if(!flag){
//         for(int i=0; i<size; i++){
//             for(int j=i+1; j<size; j++){
//                 if(*(arr+i)> *(arr+j)){
//                     swap(*(arr+i), *(arr+j));
//                 }
//             }
//         }
//     }
//     else{
//         for(int i=0; i<size; i++){
//             for(int j=i+1; j<size; j++){
//                 if(*(arr+i)< *(arr+j)){
//                     swap(*(arr+i), *(arr+j));
//                 }
//             }
//         }
//     }
// }

// // Reverse the list
// void ArrayList::reverse(){
//     int start = 0;
//     int end = size-1;
//     while(start < end){
//         swap(*(arr+start), *(arr+end));
//         start++;
//         end--;
//     }
// }

// // Resize list
// void ArrayList::resize(){
//     if(isFull()){
//         capacity+=10;
//     }
//     else if(isHalf()){
//         capacity = size;
//     }

//     string *newArray = new string [capacity];
//     for(int i=0; i<size; i++){
//         *(newArray+i)=*(arr+i);
//     }

//     delete [] arr;
//     newArray = arr;
// }

/* SEARCH INSERT POSITION */

// int insertPos(int nums[], int size, int target){

//     for(int i=0; i<size; i++){
//         if(nums[i]==target){
//             return i;
//         }

//         else{
//             if(i==0 && nums[i]>target){
//                 return i;
//             }

//             else if(i==size-1 && nums[i]<target){
//                 return i+1;
//             }
//             else if(nums[i]<target && nums[i+1]>target){
//                 return i+1;
//             }
//         }
//     }

//     return -1;
// }

// int main(){
//     int size = 4;
//     int nums[size] = {1,3,5,6};
//     int target = 7;
//     cout<< insertPos(nums, 4, target)<<endl;

// }

/* PLUS ONE */
int *plusOne(int digits[], int size)
{

    if (digits[size - 1] >= 0 && digits[size - 1] < 9)
    {
        digits[size - 1]++;
        return digits;
    }

    else if (digits[size - 1] == 9)
    {
        size++;
        int i=size-1;
        do{
            digits[i]=0;
            i--;
        }while(digits[i]==9);

        
        digits[i]+=1;
    }
    return digits;
}
int main()
{
    int size = 3;
    int digits[size] = {9};
    plusOne(digits, size);

    for (int i = 0; i < size; i++)
    {
        cout << digits[i] << " ";
    }
}