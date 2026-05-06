#include <bits/stdc++.h>
using namespace std;

void print(int a){
    cout<<a;
}

void explainPair(){
    pair<int ,int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;
    // pair<int , string , int> p2 = {1,"hello",10};
    // cout<<p2.first<<" "<<p2.second<<endl;
    pair<int , pair<int,int>>p3 = {1,{2,3}};
    cout<<p3.first<<" "<<p3.second.first<<" "<<p3.second.second<<endl;
    pair<int , int> arr[] = { {1,2} , {3,4} , {5,6}}; //array of pairs
    for (auto i : arr){//auto is used to automatically deduce the type of i, which in this case is pair<int, int>
        cout<<i.first<<" corresponds to "<<i.second<<endl;
    }

}

void explainVector() {
//When we do not know the size of the array beforehand, we can use vector which is a dynamic array that can grow in size as needed.
    // vector<int> v; //vector of integers
    // v.push_back(1);
    // v.emplace_back(2); //emplace_back is more efficient than push_back as it constructs the element in place
    /*vector <int> v2;
    cout << v2.capacity()<<endl; //returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
    v2.emplace_back(1);
    cout << v2.capacity() << endl;
    v2.emplace_back(2);
    cout << v2.capacity() << endl;
    v2.emplace_back(3);
    cout << v2.capacity() << endl;
    //vector size increses in powers of 2 to avoid frequent reallocation and copying of elements when the vector grows.
    */
   /*vector <pair <int,int>> v; //vector of pairs
   v.push_back({1,2});
    v.emplace_back(3,4);// it considers the element is a pair by default and constructs it in place, which is more efficient than push_back.
    vector <int> v2(5,10); //vector of size 5 with all elements initialized to 10
    vector <int> v3 (5); //vector of size 5 with all elements initialized to 0 or garbage values (depends on the implementation)
    vector <int>v4(v3); //copy constructor, creates a new vector v4 which is a copy of v3
*/
    vector <int> v = {1,2,3,4,5};
    vector<int> ::iterator it = v.begin();//iterator is a pointer that points to the first element of the vector, and we can use it to traverse the vector.
    it++;
    cout <<*(it)<<" "; 
    it = it +2;
    cout <<*(it)<<" ";

    vector<int> ::iterator it1 = v.end(); //iterator that points to the position after the last element of the vector, used to indicate the end of the traversal.
    vector<int> ::reverse_iterator it2 = v.rbegin(); //reverse iterator is a pointer that points to the last element of the vector, and we can use it to traverse the vector in reverse order.
    vector<int> ::reverse_iterator it3 = v.rend(); //reverse iterator that points to the position before the first element of the vector, used to indicate the end of the reverse traversal.

    


}


int main(){
    // int a;
    // cin >> a;
    // print(a);
    // explainPair();
    explainVector();
}