/*
You are given an array/list ARR consisting of N integers. Your task is to find the maximum possible sum of a non-empty subarray(contiguous) of this array.

Note: An array C is a subarray of array D if it can be obtained by deletion of several elements(possibly zero) from the beginning and the end of array D.

For e.g.- All the non-empty subarrays of array [1,2,3] are [1], [2], [3], [1,2], [2,3], [1,2,3].

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 5*10^5
-10^9 <= ARR[i] <=10^9

Time Limit: 1sec
Sample Input 1 :
4 
2 -7 -11 13
Sample Output 1:
13
Explanation for Sample 1:
The maximum sum subarray has index range [3, 3].
Sample Input 2 :
5
6 -1 3 -4 3
Sample Output 2 :
8
Explanation for Sample 2:
The maximum sum subarray has index range [0, 2].
*/




#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int N) 
{
	// Write Your Code here 
	long long maxi = arr[0];
	long long sum = 0;
	for(int i = 0; i < N; i++){
		sum += arr[i];
		maxi = max(maxi,sum);
		if(sum < 0) sum = 0;
	}       
	return maxi;
}