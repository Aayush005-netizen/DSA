#include <bits/stdc++.h>
using namespace std;

//Because the print statement is after the recursive call, the numbers will be printed in increasing order. If we had the print statement before the recursive call, the numbers would be printed in decreasing order.
//It is also the reason why it is a backtracking problem, because we are going back to the previous state after the recursive call is done.

void name5(string name, int count){
    if (count == 5) return;
    name5(name,++count);
    cout<<name<<endl;
}

int main(){
    string name = "John";
    name5(name,0);
    return 0;
}