#include <bits/stdc++.h>
using namespace std;

//Because the print statement is after the recursive call, the numbers will be printed in increasing order. If we had the print statement before the recursive call, the numbers would be printed in decreasing order.
//It is also the reason why it is a backtracking problem, because we are going back to the previous state after the recursive call is done.

void print1ton(int n){
    if (n == 0) return;
    print1ton(n-1);
    cout<<n<<" ";
}

int main(){
    int n = 10;
    print1ton(n);
}
