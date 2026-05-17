// Insertion Sort Algorithm
// Time Complexity: O(n^2) in worst and average case, O(n) in best case (when the array is already sorted)
// Space Complexity: O(1) because it is an in-place sorting algorithm
// Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages:
// 1. It is simple to implement and understand.
// 2. It is efficient for small data sets or partially sorted arrays.
// 3. It is an in-place sorting algorithm, meaning it requires only a constant amount of additional memory space.


#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

void insertion(int arr[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 ; j--){
            // If j < j-1
            if(arr[j] < arr[j-1]){
                int buffer = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = buffer;
            }
        }
    }
}

int main(){
    int arr[] = {13,46,24,52,20,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<size<<endl;
    insertion(arr,size);
    print(arr,size);
    return 0;
}