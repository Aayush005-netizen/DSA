/*Problem statement
You are given an integer, all you have to do is to find whether this number is a Fibonacci number or not.

Fn is said to be a Fibonacci sequence such that each number in Fn is the sum of its two preceding numbers, starting with 0 and 1.

Fn = F(n-1) + F(n-2)
fn is said to be a Fibonacci number if it is a part of the Fn/Fibonacci sequence.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
0 <= N <= 100000

Where ‘T’ is the number of test cases.

Where 'N' is the given number.

Time limit: 1 sec
Sample Input 1:
2
5
6
Sample Output 1:
YES
NO
Explanation of sample input 1:
In the first test case, 5 is a Fibonacci number.

In the second test case, 6 is not a Fibonacci number.
Sample Input 2:
2
1
0
Sample Output 2:
YES
YES
Explanation for sample input 2:
In the first test case, 1 is a Fibonacci number.

In the second test case, 0 is a Fibonacci number.*/


bool CheckFiboNum(int n)
{
    //  Write your code here.
    int last = 1;
    int slast = 0;
    if ( n == 0 || n == 1){return true;}
    int current = 1;
    while(current <= n){
        if (current == n){return true;}
        int buffer = current;
        current = last + slast;
        slast = last;
        last = current;
    }
    return false;
}
