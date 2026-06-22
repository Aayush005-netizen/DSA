/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
 

Note: This question is the same as 2287: Rearrange Characters to Make Target String.


*/



class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        int freq = 0;
        for(int i = 0; i < text.length(); i++){
            mpp[text[i]] += 1;
        }
        if(mpp['b'] > 0 && mpp['a'] > 0 && mpp['l']/2 > 0 && mpp['o']/2 > 0 && mpp['n'] > 0){
            int f_l = mpp['l']/2; 
            int f_o = mpp['o']/2;
            freq = min(min(min(mpp['b'] , f_l) , min(f_o , mpp['a'])) , mpp['n']);
        }
        return freq;
    }
};