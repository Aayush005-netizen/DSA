/*Problem statement
Ninja has been given a number ‘SUM’. Ninja has to print the minimum number of Fibonacci numbers whose sum is equal to ‘SUM’.

As Ninja is busy at work, he assigns this task to you. Can you help Ninja to solve this task?

Note :

1. Ninja can use the same Fibonacci number any number of times.
2. It is also guaranteed that there are always some Fibonacci numbers whose sum is equal to ‘SUM’.  
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= ‘T’ <= 50
1 <= ‘SUM’ <= 10000

Time limit: 1 sec
Sample Input 1 :
2
8
15    
Sample Output 1 :
1
2    
Explanation of sample input 1 :
As we know Fibonacci series is: 1 1 2 3 5 8 13 21 34

In the first test case, for ‘SUM’ = 8 we can use only 8.
In the second test case, for ‘SUM’ = 15 we can use only 13 + 2 = 15.
Sample Input 2 :
2
25
11    
Sample Output 2 :
3
2    
Explanation of sample input 2 :
As we know Fibonacci series is: 1 1 2 3 5 8 13 21 34

In the first test case, for ‘SUM’ = 25 we can use only 21 + 3 + 1 = 25.
In the second test case, for ‘SUM’ = 11 we can use only 8 + 3 = 11.*/




#include <bits/stdc++.h> 
int findMinFibonacciNumbers(int sum) {
    //  Write your code here.
    vector<int> fibs = {1, 1};
    int n = 2;  // counter starts at 2 since we already have {1,1}
    
    while (fibs.back() <= sum) {
        fibs.push_back(fibs[n-1] + fibs[n-2]);
        n++;
    }
    
    int count = 0;
    int i = n - 1;
    while (sum > 0) {
        while (fibs[i] > sum) i--;
        sum -= fibs[i];
        count++;
    }
    return count;
}