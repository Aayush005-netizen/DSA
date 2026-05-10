class Solution {
public:
    int reverse(int x) {
        int new_num = 0;
        if (x < 0) return -1;
        while (x > 0) {
            if (new_num > INT_MAX/10) return -1;
            new_num = (new_num * 10) + (x % 10);
            x = x / 10;
        }
        return new_num;
    }
    bool isPalindrome(int x) {
        int rev = reverse(x);
        if (rev < 0) {return false;}
        else if (rev == x) {return true;}
        else {return false;}
    }
};