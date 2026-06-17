/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character
*/


class Solution {
public:
    vector<char> reverse(vector<char>& s,int n){
        int i = 0;
        int e =n-1;
        while(i<e){
            swap(s[i],s[e]);
            e--;
            i++;
        }
        return s;
    }
    void reverseString(vector<char>& s) {
        reverse(s,s.size());
    }
};