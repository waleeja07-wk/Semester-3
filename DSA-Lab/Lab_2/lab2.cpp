#include <iostream>
using namespace std;

/* TASK 1 */
/* LEADERS OF AN ARRAY */
// int main(){
//     int n;

//     cout<<"ENTER SIZE OF ARRAY: ";
//     cin>>n;

//     int *arr = new int [n];
//     cout<<"ENTER ELEMETS OF ARRAY: ";
//     for(int i=0; i<n; i++){
//         cin>>*(arr+i);
//     }

//     int *leaders = new int [n];
//     bool isLarge = false;
//     int count = 0;
//     for(int i=0; i<n; i++){
//         isLarge = false;
//         int j = i+1;

//         while(j<n){
//             if(*(arr+j)>*(arr+i)){
//                 isLarge = true;
//             }
//             j++;
//         }

//         if(isLarge == false){
//             *(leaders+count) = *(arr+i);
//             count++;
//         }
//     }
    
//     n = count;

//     cout<<"Leaders of the array: ";
//     for(int i=0; i<n; i++){
//         cout<< *(leaders+i)<<" ";
//     }

//     delete [] arr;
//     delete [] leaders;
// }


/* TASK 2 */
/* DYNAMIC MEMORY CALCULATOR */
// int main(){
//     int n;

//     cout<<"ENTER SIZE OF BOTH ARRAYS: "<<endl;
//     cin>>n;

//     int *arr1 = new int [n];
//     cout<<"ENTER ELEMETS OF ARRAY 1: "<<endl;
//     for(int i=0; i<n; i++){
//         cin>> *(arr1+i);
//     }


//     int *arr2 = new int [n];
//     cout<<"ENTER ELEMETS OF ARRAY 2: "<<endl;
//     for(int i=0; i<n; i++){
//         cin>> *(arr2+i);
//     }

//     int *arrSum = new int [n];
//     for(int i=0; i<n; i++){
//         *(arrSum+i) = *(arr1+i) + *(arr2+i);
//     }

//     int *arrDiff = new int [n];
//     for(int i=0; i<n; i++){
//         *(arrDiff+i) = (*(arr1+i)) - (*(arr2+i));
//     }

//     int *arrPro = new int [n];
//     for(int i=0; i<n; i++){
//         *(arrPro+i) = (*(arr1+i)) * (*(arr2+i));
//     }

//     cout<<"SUM: ";
//     for(int j=0; j<n; j++){
//         cout<<*(arrSum+j)<<" ";
//     }
//     cout<<endl;

//     cout<<"DIFFERENCE: ";
//     for(int j=0; j<n; j++){
//         cout<<*(arrDiff+j)<<" ";
//     }
//     cout<<endl;

//     cout<<"PRODUCT: ";
//     for(int j=0; j<n; j++){
//         cout<<*(arrPro+j)<<" ";
//     }
//     cout<<endl;

//     delete [] arr1;
//     delete [] arr2;
//     delete [] arrSum;
//     delete [] arrDiff;
//     delete [] arrPro;

// }


/* TASK 3 */
// int* findIndices(int* nums, int target, int size)
// {
//     int *result = new int [2];
//     for(int i=0; i<size; i++){
//         for(int j=i+1; j<size; j++){
//             if(*(nums+i)+*(nums+j)==target){
//                 *(result) = i;
//                 *(result+1) = j;
//                 return result;
//             }
//         }
//     }
//     return 0;
// }

// int main(){
//     int n;

//     cout<<"ENTER SIZE OF ARRAY: "<<endl;
//     cin>>n;

//     int *arr = new int [n];
//     cout<<"ENTER ELEMENTS OF ARRAY: "<<endl;
//     for(int i=0; i<n; i++){
//         cin>>*(arr+i);
//     }

//     int target;
//     cout<<"ENTER TARGET: "<<endl;
//     cin>>target;

//     int *indices = findIndices(arr, target, n);

//     cout<<"REQUIRED INDICES: ";
//     for(int i=0; i<2; i++){
//         cout<<*(indices+i)<<" ";
//     }

//     delete [] arr;
//     delete [] indices;

// }


/* TASK 4 */
/* Find the Single Non-Repeating Element */

// int main(){
//     int arr[] = {4, 1, 2, 1, 2};
//     int n = sizeof(arr)/sizeof(*(arr));

//     int res = 0;
//     for(int i=0; i<n; i++){
//         res ^= *(arr+i);
//     }

//     cout<<"SINGLE NON REPEATING ELEMEMT: "<<res<<endl;

// }


