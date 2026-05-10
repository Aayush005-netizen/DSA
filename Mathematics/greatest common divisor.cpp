/*Problem statement
You are given two numbers, ‘X’ and ‘Y’. Your task is to find the greatest common divisor of the given two numbers.

The Greatest Common Divisor of any two integers is the largest number that divides both integers.

For Example:
You are given ‘X’ as 20 and ‘Y’ as 15. The greatest common divisor, which divides both 15 and 20, is 5. Hence the answer is 5.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= X, Y <= 10^9
Sample Input 1:
2
20 15
8 32
Sample Output 1:
5
8
Explanation:
For the first test case, the greatest common divisor which divides both 15 and 20 is 5. Hence the answer is 5.

For the second test case, the greatest common divisor which divides both 8 and 32 is 8. Hence the answer is 8.
Sample Input 2:
2
98 56
36 60
Sample Output 2:
14
12*/

int findGcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}



/*This is Eucledian Algorithm for finding GCD. It works on the principle that GCD of two numbers also divides their difference.
The algorithm repeatedly replaces the larger number with the difference of the two numbers until one of the numbers becomes zero. 
The non-zero number at this point will be the GCD of the original two numbers.*/

/*
Let's say x=18, y=48 (x is smaller here)

Iteration 1
temp = 48
y    = 18 % 48 = 18
x    = 48
After iteration 1: x=48, y=18 — they swapped!

Iteration 2
temp = 18
y    = 48 % 18 = 12
x    = 18
After iteration 2: x=18, y=12

Iteration 3
temp = 12
y    = 18 % 12 = 6
x    = 12
After iteration 3: x=12, y=6

Iteration 4
temp = 6
y    = 12 % 6 = 0
x    = 6
After iteration 4: x=6, y=0
*/