/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 105
s consists of English letters, digits, symbols and spaces.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int i = 0, j = 0, res = 0;
        while(j < s.size()){
            if(mpp.find(s[j]) == mpp.end() || mpp[s[j]] == -1){ // if the element is not in the map or if it had come once but in the current substring it is not present
                res = max(res , j - i + 1);
                mpp[s[j]] = j;
                j++;
            }
            else{
                while(i <= mpp[s[j]]){
                    mpp[s[i]] = -1;
                    i++;
                }
            }
        }
        return res;
    }
};