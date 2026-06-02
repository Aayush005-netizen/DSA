/*
You are given an array ‘A’ of size ‘N’ containing only 0s and 1s. You have to sort the array by traversing the array only once.

For Example:
For the following array:
[0 1 1 1 0 0 1]

The output should be [0 0 0 1 1 1 1].
Note:
You have to sort the array in place.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10^5
A[i] = 0 or 1

Time Limit: 1 sec.
Sample Input 1:
2
4
1 0 1 0 
6
0 1 1 0 0 0
Sample Output 1:
0 0 1 1
0 0 0 0 1 1
Explanation For Sample Output 1:
For the first test case, the sorted array will be [0 0 1 1].

For the second test case, the sorted array will be [0 0 0 0 1 1].
Sample Input 2:
2
10
0 1 1 0 1 0 1 1 0 0
8
1 1 1 0 0 1 0 1
Sample Output 2:
0 0 0 0 0 1 1 1 1 1
0 0 0 1 1 1 1 1
*/




#include <bits/stdc++.h> 
void sort0and1(int n, vector<int> &A){
    // Write your code here.
    int j = n - 1;
    for(int i = 0; i < j; i++){
        if(A[i] == 0){
            i++;
        }
        else if(A[j] == 1){
            j--;
        }
        else{
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
}