# include <bits/stdc++.h>
using namespace std;

/*void reverse (int arr[], int l , int r){ //Multivariable
    
    if(l>=r) return;

    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    reverse(arr, l+1, r-1);
    return; 
}*/

void reverse(int arr[], int i, int n){ //Single Variable
    
    if (i >= n/2 ) return;
    swap(arr[i] , arr[n - i - 1]);
    reverse(arr,i+1,5);
}

void printarray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    reverse(arr,0,5);
    printarray(arr,5);
}