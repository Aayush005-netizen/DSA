/*Problem statement
Given an integer ‘N’, your task is to write a program that returns all the divisors of ‘N’ in ascending order.



For example:
'N' = 5.
The divisors of 5 are 1, 5.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
10
Sample Output 1 :
1 2 5 10
Explanation of Sample Input 1:
The divisors of 10 are 1,2,5,10.
Sample Input 2 :
6
Sample Output 2 :
1 2 3 6
Explanation of Sample Input 2:
The divisors of 6 are 1, 2, 3, and 6.
Constraints :
1 <= 'N' <= 10^5 */

int* printDivisors(int n, int &size) {
    // Step 1: count divisors
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++; // don't double count perfect squares
        }
    }

    // Step 2: fill the array
    int* arr = new int[count];
    int idx = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            arr[idx++] = i;
            if (i != n / i)
                arr[idx++] = n / i;
        }
    }

    // Step 3: sort (since we added pairs out of order)
    sort(arr, arr + count);

    size = count; // tell the caller how many elements
    return arr;
}
