#include <bits/stdc++.h>
using namespace std;

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