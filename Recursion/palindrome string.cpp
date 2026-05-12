# include <bits/stdc++.h>
using namespace std;

bool palindrome (int i,string str, int n) {
    
    if (i >= n/2) return true;
    if (str[i] != str[n-i-1]) return false;
    return palindrome(i+1,str,n);
}

int main(){
    string str = "abcdcba";
    string str2 = "asdfgh";
    cout << palindrome(0,str,7)<<endl;
    cout << palindrome(0,str2,6);
    return 0;
}