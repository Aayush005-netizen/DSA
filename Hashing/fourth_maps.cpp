#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,5,5,45,2,454,2,4,1,45,12,45,454,45,45,12,4512,245,2,245,545,5,5,5,454,45,5,1,4,12,4,1,12,4,441,41,2,2,2,2,5,5,5,55,5,5};
    map<int,int> mpp;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        mpp[arr[i]] += 1;
    }
    cout << mpp[5] << endl;  // prints 10
    return 0;;
}