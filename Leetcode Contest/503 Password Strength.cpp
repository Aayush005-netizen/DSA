/*
You are given a string password.

The strength of the password is calculated based on the following rules:

1 point for each distinct lowercase letter ('a' to 'z').
2 points for each distinct uppercase letter ('A' to 'Z').
3 points for each distinct digit ('0' to '9').
5 points for each distinct special character from the set "!@#$".
Each character contributes at most once, even if it appears multiple times.

Return an integer denoting the strength of the password.

 

Example 1:

Input: password = "aA1!"

Output: 11

Explanation:

The distinct characters are 'a', 'A', '1' and '!'.
Thus, the strength = 1 + 2 + 3 + 5 = 11.
Example 2:

Input: password = "bbB11#"

Output: 11

Explanation:

The distinct characters are 'b', 'B', '1' and '#'.
Thus, the strength = 1 + 2 + 3 + 5 = 11.​​​​​​​
 

Constraints:

1 <= password.length <= 105
password consists of lowercase and uppercase English letters, digits, and special characters from "!@#$".
*/

class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        set <char> seen;
        for(int i = 0; i < password.length(); i++){
            if(seen.count(password[i])) {continue;}
            seen.insert(password[i]);
            if(password[i] >= 'a' && password[i] <= 'z'){
                strength += 1;
            }
            if(password[i] >= 'A' && password[i] <= 'Z'){
                strength += 2;
            }
            else if(password[i] >= '0' && password[i] <= '9'){
                strength += 3;
            }
            if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$'){
                strength+= 5;
            }
        }
        return strength;
    }
};