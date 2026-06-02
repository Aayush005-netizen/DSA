/*
Problem statement
You are given two non-negative integers, ‘NUM1’ and ‘NUM2’, in the form of strings. Return the sum of both strings.



Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Example:
Let ‘NUM1’ be: “5”
Let ‘NUM2’ be: “21”
The sum of both numbers will be: “26”.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= |NUM1|, |NUM2| <= 10^5

NUM1 and NUM2 don’t have leading zeroes.
Where |NUM1| and |NUM2| denote the length of the respective strings.

Time limit: 1 sec
Sample Input 1 :
2
5 21
10 9
Sample output 1 :
26
19
Explanation For Sample Output 1 :
For the first test case:
The sum of both numbers will be: “26”.

For the second test case:
The sum of both numbers will be: “19”.
Sample Input 2 :
2
9 9
21 10
Sample output 2 :
18
31
*/

#include <bits/stdc++.h> 
string stringSum(string &num1, string &num2) {
    int i = num1.size() - 1;  // pointer at end of num1
    int j = num2.size() - 1;  // pointer at end of num2
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += (num1[i--] - '0');  // convert char to digit
        if (j >= 0) sum += (num2[j--] - '0');

        carry = sum / 10;
        result += to_string(sum % 10);  // store last digit
    }

    reverse(result.begin(), result.end());  // digits were added in reverse
    return result;
}