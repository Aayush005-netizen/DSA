//Selection sort is a simple sorting algorithm that works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and swapping it with the first unsorted element. The algorithm maintains two subarrays: the sorted subarray and the unsorted subarray. Initially, the sorted subarray is empty and the unsorted subarray contains all the elements. The algorithm iteratively selects the minimum element from the unsorted subarray and moves it to the end of the sorted subarray until all elements are sorted.
//Time complexity: O(n^2) in all cases (best, average, worst) because it always requires two nested loops to complete the sorting process.


#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

void selection(int arr[], int n){
    
    for(int i  = 0; i < n-1; i++){
        int minindex = i;
        for(int j = i+1; j < n; j++){
            if(arr[minindex] > arr[j]){minindex = j;}
        }
        int buffer = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = buffer;
    }
}

int main(){
    int arr[] = {13,46,24,52,20,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<size<<endl;
    selection(arr,size);
    print(arr,size);
    return 0;
}