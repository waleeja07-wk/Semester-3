#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* ======= LAB LEARNING =======*/

//  int sumArray(int size, int *ptr){
//     double sum = 0;
//     for(int i=0; i<size; i++){
//         sum += *ptr++;
//     }
//     return sum;
//  }
// int main(){
// //     int a = 10;
// //     int *ptr = &a;
// //     int *pptr = &ptr;

// //     cout << ptr <<endl;
// //    (*ptr)++ ;

// //     cout << ptr <<endl;
// //      cout << a <<endl;

//     // int a = 10;
//     // double b = 6.5;
//     // char c = 'A';

//     // void *ptr = nullptr;

//     // ptr = &a;
//     // ptr = &b;
//     // ptr = &c;

//     // cout << ptr <<endl;
//     // cout << *((double*)ptr) <<endl;
//     // cout << *(static_cast<double *> (ptr))<<endl;


//     // double marks[] = {20, 30, 40};

//     // double *ptr = marks;

//     // cout<<*ptr++<<endl; // first dereference then increase
//     // cout<<*ptr++<<endl;
//     // cout<<*ptr <<endl;
    
//     string firstName = "Waleeja";
//     string fullName = firstName + " Khan";
//     cout << fullName << endl;
// }

/* ======== LAB TASKS ==========*/

/* TASK 1*/
/* Remove Duplicates In-Place */

// int removeDuplicates(int* arr, int n){
    
//     for(int i = 0; i<n; i++){
//         for(int j = i+1; j<n; j++){

//             if(*(arr+i)==*(arr+j)){
//                 int k;
//             while(j<n && arr[j]==arr[i]){
//             for(k=j; k<n-1; k++){
//                 *(arr+k)=*(arr+k+1);
//                }
//                n--;
//             }
//         }
            
//         }
//     }
//     return n;
// }

// int main(){
//     int arr[] = {4, 2, 4, 7, 2, 9, 4};
//     int size = sizeof(arr)/sizeof(*(arr));

//     size = removeDuplicates(arr, size);
    
//      for(int k = 0; k < size; k++){
//            cout<<*(arr+k)<<" ";
//         }
//         cout<<endl;

// }


/* TASK 2 */ 
/* Second Smallest Without Sorting */

// int secondSmallest(int *arr, int size){
//     int smallest =  INT_MAX;
//     int secSmallest = smallest;
//     for(int i=0; i<size; i++){
//         if(*(arr+i)<smallest){
//             secSmallest = smallest;
//             smallest = *(arr+i);
            
//         }
//         else if(*(arr+i)>smallest && *(arr+i)<secSmallest){
//             secSmallest = *(arr+i);
//         }
//     }
     
//     if(secSmallest == INT_MAX){
//         return -1;
//     }

//     else{
//       return secSmallest;
//     }
   
// }

// int main(){
//     int arr[] = {10, 8, 5, 10, 3, 5};
//     int size = sizeof(arr)/ sizeof(*(arr));

//    int result = secondSmallest(arr, size);
//    if(result==-1){
//         cout<<"Second Smallest Not Found"<<endl;
//    }

//    else{
//         cout<< "Second Smallest = " <<result <<endl;
//    }

// }


/* TASK 3 */
/* Rearrange Positive and Negative Values */

// void rearrangeArray(int* arr, int size){
//    int start = 0;
//    int end = size-1;

//    while(start<end){
//     if(*(arr+start)<0){
//         start++;
//     }

//     if(arr[end]<0){
//         swap(*(arr+start),*(arr+end));   
//         start++; 
//         end--;
//     }
//     else{
//         end--;
//     }

//    }
// }


// int main(){
//     int arr[] = {4, -2, 7, -8, 3, -1, 5};
//     int size = sizeof(arr)/ sizeof(*(arr));

//     rearrangeArray(arr, size);

//     for(int i=0; i<size; i++){
//     cout<<*(arr+i)<<" ";
//    }
// }


