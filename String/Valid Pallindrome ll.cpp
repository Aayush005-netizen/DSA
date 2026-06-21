/*
Ninja’s friend challenged him with a trick question. He gave him a string ‘S’ and asked him if it is possible to make this string palindrome by deleting one character from the string. Can you help the ninja to solve this problem?

You are given a string ‘S’ of size ‘N’.You have to determine whether it is possible to make the string palindrome by deleting at most one character.

For Example
If the string is ‘AZBCDCBA’, the answer will be YES as we can delete the character ‘Z’ and the remaining string is a palindrome. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^5.

Time limit: 1 sec
Sample Input 1:
2
8
AZBCDCBA
3
ABA
Sample Output 1:
YES
YES
Explanation of sample input 1:
For the first test case,
If we remove the letter ‘Z’ from the string , the remaining string ‘ABCDCBA’ is palindromic.Hence, the answer is YES.

For the second test case:
The given string is already palindromic. Hence, the answer is YES.
Sample Input 2:
2
6
ROSSVR
6
VWHGWV
Sample Output 2:
NO
YES
*/



#include <bits/stdc++.h> 
bool validPalindrome(int n, string &s)
{
    // Write your code here.
    int i = 0;
    int j = n-1;
    int count = 0;
    while(i <= j && count < 2){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else {
            if(s[i] == s[j-1]){
                i++;
                j -= 2;
                count++;
            }
            else if(s[i+1] == s[j]){
                i += 2;
                j--;
                count++;
            }
            else{return false;}
        }
    }
    if(count == 2){return false;}
    else{return true;}
}