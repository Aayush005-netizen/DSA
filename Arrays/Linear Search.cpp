/*Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers’ and an integer ’X’. Your task is to find out the first instance of X in the array. If no such instance exists, return -1.

Note:

Consider 0-based indexing of the array.
For Example :
Input : arr[] = {5, 1, 3, 4, 3}, X = 3
Output : 2
There are two instances of 3 in the array -  2 and 4. Since we need to return the first instance our result is 2.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10^5
0 <= ARR[i] <= 10^9

Time Limit: 1 sec
Sample Input 1 :
2
6 1
2 6 2 8 4 5
1 1 
1 
Sample Output 1 :
-1
 0
Explanation Of Sample Output 1 :
Since there is no instance of 1 in the input array we return -1.
In the second test case, the only occurrence of 1 is 0.
Sample Input 2 :
1
5 3
5 1 3 4 3
Sample Output 2 :
2*/




/*#include <bits/stdc++.h> 
int linearSearch(vector<int> &a, int x) {
    //    Write your code here
    int size = a.size();
    for(int i = 0; i < size; i++){
        if(a[i] == x){return i;}
    }
    return -1;
}*/
#include <bits/stdc++.h> 
int linearSearch(vector<int> &a, int x) {
    //    Write your code here
    for(auto it = a.begin(); it != a.end(); it++){
        if(*it == x){return it - a.begin();}
    }
    return -1;
}