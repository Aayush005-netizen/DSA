/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/




class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mpp;
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(mpp.find(t[i]) == mpp.end() || mpp[t[i]] == 0){
                return false;
            }
            mpp[t[i]]--;
        }
        return true;
    }
};

/*class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> counter;

        for (char ch : s) {
            counter[ch] = counter[ch] + 1;
        }

        for (char ch : t) {
            if (counter.find(ch) == counter.end() || counter[ch] == 0) {
                return false;
            }
            counter[ch] = counter[ch] - 1;
        }

        return true;        
    }
};*/