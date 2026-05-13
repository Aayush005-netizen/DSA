// This code is for counting the frequency of characters in a string using hashing.
// The user is prompted to enter a string, and the code creates a hash array to count the frequency of each character in the input string.
// The index of the hash array corresponds to the character (where 'a' is at index 0, 'b' is at index 1, and so on), and the value at that index represents the frequency of that character in the input string.
// Finally, the user can query the frequency of any character, and the code will return the count from the hash array. Note that the code only counts lowercase letters from 'a' to 'z'. If the user queries a character outside this range, the code will return 0.
// This code will only identify the frequency of lowercase letters in the input string. If there are uppercase letters or other characters, they will be ignored in the frequency count.




#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++){    // ✅ i < s.size()
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cout << "Enter the char: ";
        cin >> c;
        cout << hash[c] << endl;
    }
    return 0;
}