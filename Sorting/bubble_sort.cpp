//Bubble Sort Algorithm
//Time Complexity: O(n^2) in worst and average case, O(n) in best case (when the array is already sorted)
//Space Complexity: O(1) because it is an in-place sorting algorithm
//Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The algorithm gets its name from the way smaller elements "bubble" to the top of the list (beginning) while larger elements sink to the bottom (end) with each pass. Bubble sort is not efficient for large datasets, but it is easy to understand and implement, making it a good choice for educational purposes.
//The algorithm works as follows:
//1. Compare the first two elements of the array. If the first element is greater than the second element, swap them.
//2. Move to the next pair of elements and repeat the comparison and swap if necessary.
//3. Continue this process until the end of the array is reached. At this point, the largest element will have "bubbled" to the end of the array.
//4. Repeat the entire process for the remaining unsorted portion of the array (excluding the last element which is now sorted) until the entire array is sorted.


#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

void binary(int arr[],int n){

    for (int i = 0; n-i-1 > 0; i++){
        for (int j = 0; j < n-i-1; j++){  //When j = n-i-1, you access arr[j+1] which is arr[n-i] — that's outside the array. That's where all those garbage values are coming from.
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {13,46,24,52,20,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<size<<endl;
    binary(arr,size);
    print(arr,size);
    return 0;
}