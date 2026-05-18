// Quick Sort Algorithm
// Time Complexity: O(n log n) in average and best case, O(n^2) in worst case (when the array is already sorted or reverse sorted)
// Space Complexity: O(log n) on average and best case, O(n) in worst case (when the array is already sorted or reverse sorted) due to recursive stack space
// Quick sort is a divide-and-conquer algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting. The algorithm can be described as follows:
// 1. Choose a pivot element from the array. Common strategies for choosing the pivot include selecting the first element, the last element, the middle element, or a random element.
// 2. Partition the array into two sub-arrays: elements less than or equal to the pivot go to the left of the pivot, and elements greater than the pivot go to the right.
// 3. Recursively apply the above steps to the sub-arrays on the left and right of the pivot until the base case is reached (when the sub-array has one or zero elements, which are inherently sorted).





#include<bits/stdc++.h>
using namespace std;

void print(vector <int> &v){
    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
}

/*void quick_ascending(vector <int> &v, int low, int high){
    if(low >= high){return;}

    int pivot = v[low];
    int i = low;
    int j = high;
    while(i<=j){
        if(v[i] > pivot && v[j] <= pivot){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
        else if (v[i] <= pivot) {i++;}
        else if (v[j] > pivot) {j--;}
        else{continue;}
    }
    v[low] = v[j];
    v[j] = pivot;

    quick_ascending(v,low,j-1);
    quick_ascending(v,j+1,high);

}*/


void quick_descending(vector<int> &v, int low, int high){
    if(low >= high){ return; }

    int pivot = v[low];
    int i = low;
    int j = high;
    while(i <= j){
        while(i <= high && v[i] > pivot) i++;   // find element <= pivot from left
        while(j >= low  && v[j] <= pivot) j--;  // find element > pivot from right
        if(i < j){
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    swap(v[low], v[j]);  // place pivot

    quick_descending(v, low, j-1);
    quick_descending(v, j+1, high);
}



/*void quick_descending(vector <int> &v, int low, int high){
    if(low >= high){return;}

    int pivot = v[low];
    int i = low; //big
    int j = high; //small
    while(i<=j){
        if(v[i] <= pivot && v[j] > pivot){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
        else if (v[i] > pivot) {i++;}
        else if (v[j] <= pivot) {j--;}
        else{continue;}
    }
    swap(v[low], v[j]);

    quick_descending(v,low,j-1);
    quick_descending(v,j+1,high);

}*/

/*int main(){
    vector<int> v = {13,46,24,52,20,9};
    int n = v.size();
    quick_descending(v,0,n-1);
    print(v);
    return 0;
}*/

int main(){
    vector<int> v = {13,46,24,52,20,9};
    int n = v.size();
    cout << "Before sort: ";
    print(v);
    cout << endl;
    quick_descending(v, 0, n-1);
    cout << "After sort: ";
    print(v);
    cout << endl;
    return 0;
}