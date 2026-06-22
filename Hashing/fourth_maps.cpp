// This code demonstrates the use of maps and unordered maps in C++ to count the frequency of elements in an array. The first part of the code uses a map, which is an ordered data structure that stores key-value pairs, while the second part uses an unordered map, which is a hash table-based data structure that also stores key-value pairs but does not maintain any order. Both implementations achieve the same goal of counting the occurrences of each number in the input array and printing the frequency of the number 5.
// The code initializes an array of integers and then iterates through the array to populate the map or unordered map with the frequency of each integer. Finally, it prints the frequency of the number 5 from the respective data structure.
// Note: The frequency of the number 5 in the given array is 10, which is printed in both cases.
// The use of maps and unordered maps allows for efficient counting and retrieval of frequencies, making it a common approach for such problems in C++.
// The time complexity of both implementations is O(n) for counting the frequencies, where n is the size of the input array. The retrieval of the frequency for a specific number (like 5) is O(log m) for the map and O(1) for the unordered map, where m is the number of unique elements in the array.
// It is so because maps in C++ are typically implemented as balanced binary search trees (like Red-Black Trees), which have a logarithmic time complexity for search operations, while unordered maps are implemented as hash tables, which have an average constant time complexity for search operations.
// Worst case happens in unordered maps when there are many collisions (i.e., multiple keys hash to the same index), which can degrade the performance to O(n) in the worst case. However, with a good hash function and proper resizing, this is generally not a concern in practice.
// In map any data structure can be a key but in unordered map only hashable data structures can be a key. For example, in C++, you can use a pair as a key in a map, but you cannot use it as a key in an unordered map unless you provide a custom hash function for it. This is because unordered maps rely on hashing to store and retrieve keys efficiently, and not all data structures have built-in hash functions.


#include<bits/stdc++.h>
using namespace std;
/*
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
*/
int main(){
    int arr[] = {1,2,5,5,45,2,454,2,4,1,45,12,45,454,45,45,12,4512,245,2,245,545,5,5,5,454,45,5,1,4,12,4,1,12,4,441,41,2,2,2,2,5,5,5,55,5,5};
    unordered_map<int,int> mpp;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        mpp[arr[i]] += 1;
    }
    cout << mpp[5] << endl;  // prints 10
    return 0;
}