#include<bits/stdc++.h>
using namespace std;

// Hashing is a technique used to store and retrieve data efficiently. In this code, we are using a simple hash array to count the occurrences of each number in the input array. The index of the hash array corresponds to the number, and the value at that index represents the frequency of that number in the input array.
// This code is for counting the frequency of elements in an array using hashing.
// The user is prompted to enter the number of elements in the array, followed by the elements themselves.
// The code then creates a hash array to count the frequency of each element in the input array.
// Finally, the user can query the frequency of any number, and the code will return the count from the hash array.
// Note: The hash array size is set to 6, which means it can only count frequencies for numbers from 0 to 5.

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cout<<"enter the element: ";
        cin >> arr[i];
    }
    //int arr[5] = {1,2,2,4,3};
    int hash[6] = {0};

    for (int i = 0; i<n; i++){
        hash[arr[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number";
        cin>>number;
        if(number>=n){cout<<0;
            return 0;}

        cout<<"Frequency is: "<< hash[number] <<endl;
    }

    return 0;
}