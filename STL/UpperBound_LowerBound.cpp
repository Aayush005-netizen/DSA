//Q1 Find the First occurence of a X in a sorted array. If it does not exists, print -1.
//Q2 Find the Last occurence of a X in a sorted array. If it does not exists, print -1.
//Q3 Find the Largest Number which is smaller than X in a sorted array. If no number exists then return -1.
//Q4 Find the Smallest Number which is smaller than X in a sorted array. If no number exists then return -1.


#include <bits/stdc++.h>
using namespace std;

int first_occurence( int arr[], int n, int x){
    int ind = lower_bound(arr , arr + n , x) - arr;
    if (ind != n && arr[ind] == x){
        return ind;
    }
    else {
        return -1;
    }
    
}

int last_occurence(int arr[], int n, int x){
    int ind = upper_bound(arr, arr + n, x) - arr;
    ind--;
    if(ind >= 0 && arr[ind] == x){
        return ind;
    }
    else{
        return -1;
    }
}

int largest_number(int arr[], int n, int x){
    int ind = lower_bound(arr, arr + n, x) - arr;
    if(ind > 0) return arr[ind - 1];
    else return -1;
}

int smallest_number(int arr[], int n, int x){
    int ind = upper_bound(arr, arr + n, x) - arr;
    if(ind != n) return arr[ind];
    else return -1;
}

int main(){
    int arr[] = {1,4,4,4,4,9,9,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cin>>x;
    //int result = first_occurence(arr, n, x);
    //int result = last_occurence(arr, n, x);
    //int result = largest_number(arr, n, x);
    //int result = smallest_number(arr, n, x);
    cout << result << endl;
}