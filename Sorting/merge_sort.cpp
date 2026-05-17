// Merge Sort Algorithm
// Time Complexity: O(n log n) in all cases (best, average, and worst)
// Space Complexity: O(n) because of the temporary array used for merging
// Merge sort is a divide-and-conquer algorithm that breaks down a list into several sublists until each sublist consists of a single element. Then, it merges those sublists in a manner that results in a sorted list. The algorithm can be described as follows:
// 1. If the list is of length 0 or 1, it is already sorted. Return the list.
// 2. Divide the list into two halves.
// 3. Recursively sort both halves.
// 4. Merge the two halves back together in a sorted manner.



#include<bits/stdc++.h>
using namespace std;

void print(vector <int> &v){
    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
}

void merge(vector<int> &v,int low, int mid, int high){
    vector<int>temp;
    int i = low;
    int j = mid+1;
    while(i <= mid && j <= high ){
        if(v[i] <= v[j]){
            temp.emplace_back(v[i]);
            i++;
        }
        else{
            temp.emplace_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.emplace_back(v[i]);
        i++;
    }
    while(j<=high){
        temp.emplace_back(v[j]);
        j++;
    }
    // add this at the end of merge()
    for(int k = low; k <= high; k++){
        v[k] = temp[k - low];
    }
}

void merge_sort(vector<int>&arr, int low, int high){
    if(low >= high){return;}
    int mid = (low + high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr,low,mid,high);
}

int main(){
    vector<int> v = {13,46,24,52,20,9};
    merge_sort(v,0,v.size()-1);
    print(v);
    return 0;
}