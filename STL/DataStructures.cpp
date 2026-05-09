#include <bits/stdc++.h>
using namespace std;

void print(int a){
    cout<<a;
}

void printMap(map<int,int> mpp){
    for(auto it : mpp){
        cout<< it.first <<" corresponds to "<<it.second<<endl;
    }
}

void printVector(vector<int> v){
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *(it) <<" ";
    }
    cout << endl;
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
    vector<int> v; //vector of integers
    v.push_back(1);
    v.emplace_back(2); //emplace_back is more efficient than push_back as it constructs the element in place
    vector <int> v2;
    cout << v2.capacity()<<endl; //returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
    v2.emplace_back(1);
    cout << v2.capacity() << endl;
    v2.emplace_back(2);
    cout << v2.capacity() << endl;
    v2.emplace_back(3);
    cout << v2.capacity() << endl;
    //vector size increses in powers of 2 to avoid frequent reallocation and copying of elements when the vector grows.
    
    vector <pair <int,int>> vp; //vector of pairs
    vp.push_back({1,2});
    vp.emplace_back(3,4);// it considers the element is a pair by default and constructs it in place, which is more efficient than push_back.
    vector <int> v2(5,10); //vector of size 5 with all elements initialized to 10
    vector <int> v3 (5); //vector of size 5 with all elements initialized to 0 or garbage values (depends on the implementation)
    vector <int>v4(v3); //copy constructor, creates a new vector v4 which is a copy of v3

    vector <int> v = {1,2,3,4,5};
    vector<int> ::iterator it = v.begin();//iterator is a pointer that points to the first element of the vector, and we can use it to traverse the vector.
    it++;
    cout <<*(it)<<" "; 
    it = it +2;
    cout <<*(it)<<" ";

    vector<int> ::iterator it1 = v.end(); //iterator that points to the position after the last element of the vector, used to indicate the end of the traversal.
    vector<int> ::reverse_iterator it2 = v.rbegin(); //reverse iterator is a pointer that points to the last element of the vector, and we can use it to traverse the vector in reverse order.
    vector<int> ::reverse_iterator it3 = v.rend(); //reverse iterator that points to the position before the first element of the vector, used to indicate the end of the reverse traversal.

    cout <<v[0]<<" "<<v.at(1)<<endl; //both are used to access the elements of the vector, but at() also checks for out of range errors and throws an exception if the index is out of range, while [] does not check for out of range errors and may lead to undefined behavior if the index is out of range.
    cout <<v.back()<<endl; //returns the last element of the vector

    for (vector <int> :: iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) <<" ";
    }
    cout << endl;

    for (auto it = v.begin(); it != v.end() ; it++){ //auto is used to automatically deduce the type of it, which in this case is vector<int>::iterator
        cout << *(it) <<" ";
    }
    cout << endl;
    for (auto it : v){ //auto is used to automatically deduce the type of it, which in this case is int
        cout << it <<" ";
    }
    cout<< endl;

    v.erase(v.begin() + 1); //erase the element at index 1
    v.erase(v.begin() + 1, v.begin() + 4); //erase the elements from index 1 to index 3 (4-1)

    //{100,100}
    vector<int> v(2,100); //vector of size 2 with all elements initialized to 100
    v.insert(v.begin() , 300); //insert 300 at the beginning of the vector {300,100,100}
    v.insert(v.begin()+1 , 2, 10); //insert 2 elements of value 10 at index 1 {300,10,10,100,100}
    printVector(v);

    vector<int> copy(2,50); //vector of size 2 with all elements initialized to 50
    v.insert(v.begin(), copy.begin(), copy.end()); //insert the elements of the copy vector at the beginning of the vector v {50,50,300,10,10,100,100}
    printVector(v);

    vector<int> copy1 = {1,2,3,4,5}; //vector of size 5 with all elements initialized to 2,3,4,5
    v.insert(v.begin() +2 , copy1.begin() + 2 , copy1.begin() + 4); //insert the elements from index 2 to index 3 (4-2) of the copy1 vector at index 2 of the vector v {50,50,4,5,300,10,10,100,100}
    printVector(v);

    vector<int> copy2 = {1000,2000,3000,4000,5000};
    v.insert(v.end(), copy2.begin(), copy2.end() - 2); //insert the elements from index 0 to index 2 (5-2) of the copy2 vector at the end of the vector v {50,50,4,5,300,10,10,100,100,1000,2000}
    printVector(v);

    vector<int> v = {10,20};
    cout <<v.size()<<endl; //returns the number of elements in the vector
    cout <<v.capacity()<<endl; //returns the size of the storage space currently allocated for

    v.pop_back(); //removes the last element of the vector
    printVector(v);
    cout <<v.capacity()<<endl; //capacity does not change after pop_back() as it does not deallocate the memory, it just reduces the size of the vector by one.

    vector <int> v1 = {1,2,3,4,5};
    vector <int> v2 = {6,7,8,9,10};
    v1.swap(v2); //swaps the contents of the two vectors
    printVector(v1);
    printVector(v2);

    v1.clear(); //removes all the elements from the vector, but does not change the capacity of the vector

    cout <<v1.empty()<<endl; //returns true if the vector is empty, false otherwise
    
}

void explainList(){
    //list is a doubly linked list that allows for efficient insertion and deletion of elements at any position in the list, but does not allow for random access to elements like a vector does.
    list<int> ls;
    ls.push_back(1); //inserts 1 at the end of the list
    ls.push_front(2); //inserts 2 at the beginning of the list
    ls.emplace_back(3); //inserts 3 at the end of the list
    ls.emplace_front(4); //inserts 4 at the beginning of the list
}

void explainDeque(){
    deque<int>dq; //deque is a double ended queue that allows for efficient insertion and deletion of elements at both the front and the back of the queue, but does not allow for random access to elements like a vector does.
    dq.push_back(1); //inserts 1 at the end of the deque
    dq.push_front(2); //inserts 2 at the beginning of the deque
    dq.emplace_back(3); //inserts 3 at the end of the deque
    dq.emplace_front(4); //inserts 4 at the beginning of the deque

    dq.pop_back(); //removes the last element of the deque
    dq.pop_front(); //removes the first element of the deque

    dq.back(); //returns the last element of the deque
    dq.front(); //returns the first element of the deque

    dq.back() = 10; //modifies the last element of the deque
    dq.front() = 20; //modifies the first element of the deque
}

void explainStack(){
    stack<int> st; //stack is a data structure that follows the Last In First Out (LIFO) principle, where the last element added to the stack is the first one to be removed.
    // functions in stack: push(), pop(), top(), empty(), size()
    st.push(1); //inserts 1 at the top of the stack
    st.push(2); //inserts 2 at the top of the stack
    st.push(3); //inserts 3 at the top of the stack

    st.pop(); //removes the top element of the stack
    cout <<st.top()<<endl; //returns the top element of the stack
    cout <<st.empty()<<endl; //returns true if the stack is empty, false otherwise
    cout <<st.size()<<endl; //returns the number of elements in the stack
    
    stack<int> st1,st2;
    st1.swap(st2); //swaps the contents of the two stacks
}

void explainQueue(){
    queue<int> q; //queue is a data structure that follows the First In First Out (FIFO) principle, where the first element added to the queue is the first one to be removed.
    // functions in queue: push(), pop(), front(), back(), empty(), size()
    q.push(1); //inserts 1 at the back of the queue
    q.push(2); //inserts 2 at the back of the queue
    q.emplace(3); //inserts 3 at the back of the queue

    q.pop(); //removes the front element of the queue
    cout <<q.front()<<endl; //returns the front element of the queue
    cout <<q.back()<<endl; //returns the back element of the queue
    cout <<q.empty()<<endl; //returns true if the queue is empty, false otherwise
    cout <<q.size()<<endl; //returns the number of elements in the queue

    q.back() += 10; //modifies the back element of the queue
    q.front() += 20; //modifies the front element of the queue

    queue<int> q1,q2;
    q1.swap(q2); //swaps the contents of the two queues
}

void explainPriorityQueue(){
    priority_queue<int> pq; //priority queue is a data structure that allows for efficient retrieval of the maximum (or minimum) element in the queue, where the elements are ordered based on their priority.
    // functions in priority_queue: push(), pop(), top(), empty(), size()
    pq.push(1); //inserts 1 into the priority queue {1}
    pq.push(2); //inserts 2 into the priority queue {2, 1}
    pq.emplace(3); //inserts 3 into the priority queue {3, 2, 1}

    pq.pop(); //removes the maximum element from the priority queue
    cout <<pq.top()<<endl; //returns the maximum element from the priority queue, which is the element with the highest priority, in this case, it will return 2 as it is the maximum element in the priority queue after popping 3.
    cout <<pq.empty()<<endl; //returns true if the priority queue is empty, false otherwise
    cout <<pq.size()<<endl; //returns the number of elements in the priority queue

    priority_queue<int> pq1,pq2;
    pq1.swap(pq2); //swaps the contents of the two priority queues

    priority_queue<int, vector<int>, greater<int>> minpq; //min priority queue, where the minimum element has the highest priority
    minpq.push(1); //inserts 1 into the min priority queue {1}
    minpq.push(2); //inserts 2 into the min priority queue {1, 2}
    minpq.emplace(3); //inserts 3 into the min priority queue {1, 2, 3}

    cout<< minpq.top() << endl; //returns the minimum element from the min priority queue, which is the element with the highest priority, in this case, it will return 1 as it is the minimum element in the min priority queue
}

void explainSet(){
    set<int> s; //set is a data structure that stores unique elements in a sorted order, where the elements are ordered based on their value.
    // functions in set: insert(), erase(), find(), count(), empty(), size()
    s.insert(1); //inserts 1 into the set {1}
    s.insert(2); //inserts 2 into the set {1, 2}
    s.insert(3); //inserts 3 into the set {1, 2, 3}

    s.erase(2); //removes 2 from the set {1, 3}
    auto it1 = s.find(1000); //returns s.end() as 1000 is not found in the set
    cout<<*(it1)<<endl; //dereferencing the iterator it1 will lead to undefined behavior as it1 is equal to s.end(), which is a special iterator that does not point to any element in the set.
    cout << (s.find(3) != s.end()) << endl; //returns true if 3 is found in the set, false otherwise
    cout <<s.count(1)<<endl; //returns the number of occurrences of 1 in the set, which is either 0 or 1 as sets do not allow duplicate elements
    cout <<s.empty()<<endl; //returns true if the set is empty, false otherwise
    cout <<s.size()<<endl; //returns the number of elements in the set

    set<int> s1,s2;
    s1.swap(s2); //swaps the contents of the two sets

    int cnt = s.count(1); //returns the number of occurrences of 1 in the set, which is either 0 or 1 as sets do not allow duplicate elements
    s.erase(it1); //removes the element pointed to by the iterator it1 from the set, but since it1 is equal to s.end(), which is a special iterator that does not point to any element in the set, this operation will not remove any element from the set and will not cause any error.

    set<int> st = {1,2,3,4,5};
    auto it1 = st.find(2); //returns an iterator pointing to the element 2 in the set
    auto it2 = st.find(4); //returns an iterator pointing to the element 4 in the set
    st.erase(it1, it2); //removes the elements from the set in the range [it1, it2), which means it will remove the elements 2 and 3 from the set, but will not remove the element 4 as it is not included in the range.

    auto it = st.lower_bound(2); //returns an iterator pointing to the first element in the set that is greater than or equal to 2, which means it will return an iterator pointing to the element 2 in the set as 2 is the first element that is greater than or equal to 2.
    auto it = st.upper_bound(3); //returns an iterator pointing to the first element in the set that is greater than 3, which means it will return an iterator pointing to the element 4 in the set as 4 is the first element that is greater than 3.
}

void explainMultiSet(){
    //multiset is a data structure that stores multiple occurrences of elements in a sorted order, where the elements are ordered based on their value.

    mutliset<int> ms;
    ms.insert(1); //inserts 1 into the multiset {1}
    ms.insert(1); //inserts another 1 into the multiset {1, 1}
    ms.insert(1); //inserts another 1 into the multiset {1, 1, 1}

    ms.erase(1); //removes all occurrences of 1 from the multiset, which means it will remove all three occurrences of 1 from the multiset and the multiset will become empty.
    
    int cnt = ms.count(1); //returns the number of occurrences of 1 in the multiset, which is 0 as all occurrences of 1 have been removed from the multiset.

    ms.erase(ms.find(1)); //removes a single occurrence of 1 from the multiset, which means it will remove one occurrence of 1 from the multiset and the multiset will still contain two occurrences of 1.
    ms.erase(ms.find(1), ms.find(1) + 2); //removes the elements from the multiset in the range [ms.find(1), ms.find(1) + 2), which means it will remove two occurrences of 1 from the multiset and the multiset will become empty.
}

void explainUSet(){
    unordered_set<int> us; //unordered_set is a data structure that stores unique elements in an unordered manner, where the elements are not ordered based on their value, but rather based on their hash value.
    // lower_bound() and upper_bound() functions are not available in unordered_set as it does not maintain any order among the elements, so we cannot use these functions to find the range of elements in an unordered_set.
    // all functions are similar to set, but the elements are stored in an unordered manner, so the time complexity of the functions may vary based on the hash function used and the number of collisions in the unordered_set.
    // functions in unordered_set: insert(), erase(), find(), count(), empty(), size()
    // it has better complexity for insert(), erase(), find(), and count() functions compared to set, as it uses a hash table to store the elements, which allows for average case O(1) time complexity for these functions, while set has O(log n) time complexity for these functions as it uses a balanced binary search tree to store the elements.
    // For most cases complexity remains O(1) for unordered_set, but in worst case when there are many collisions, the complexity can degrade to O(n) as it may have to traverse the entire bucket to find the element.
}

void explainMap(){
    //Sorted key-value pairs, where the keys are ordered based on their value, and each key is unique, which means that each key can only have one corresponding value in the map.
    //generally worke with complexity of O(log n) for insert(), erase(), find(), and count() functions, as it uses a balanced binary search tree to store the key-value pairs, which allows for efficient searching, insertion, and deletion of elements based on their keys.
    map <int,int> mpp; //map is a data structure that stores key-value pairs in a sorted order, where the keys are ordered based on their value.
    // functions in map: insert(), erase(), find(), count(), empty(), size()
    map<int, pair<int,int>> mpp2; //map of key-value pairs, where the value is a pair of integers
    map< pair <int,int>, int> mpp3; //map of key-value pairs, where the key is a pair of integers and the value is an integer

    mpp[1] = 2; //inserts a key-value pair (1, 2) into the map
    mpp.insert({3,4}); //inserts a key-value pair (3, 4) into the map
    mpp.emplace(5,6); //inserts a key-value pair (5, 6) into the map

    mpp2[1] = {2,3}; //inserts a key-value pair (1, {2, 3}) into the map mpp2, where the key is an integer 1 and the value is a pair of integers (2, 3)
    mpp2.insert({3,{4,5}}); //inserts a key-value pair (3, {4, 5}) into the map mpp2, where the key is an integer 3 and the value is a pair of integers (4, 5)
    mpp3[{2,3}] = 10; //inserts a key-value pair ({2, 3}, 10) into the map mpp3, where the key is a pair of integers (2, 3) and the value is an integer 10
    cout<< mpp[1];
    cout<< mpp[5]; //if the key 5 is not found in the map, it will insert a key-value pair (5, 0) into the map and return the value 0, as the default value for integers is 0.

    auto it = mpp.find(3); //returns an iterator pointing to the key-value pair with key 3 in the map, which means it will return an iterator pointing to the key-value pair (3, 4) in the map.
    cout << *(it).second << endl; //dereferencing the iterator it and accessing the second element of the key-value pair will return the value 4, as the key-value pair (3, 4) is found in the map.
}

void explainMultiMap(){
    //multimap is a data structure that stores multiple occurrences of key-value pairs in a sorted order, where the keys are ordered based on their value, but allows for duplicate keys.
    //it is different from map as it allows for duplicate keys, which means that multiple key-value pairs can have the same key, but different values.
    //In multimap, the insert() function will insert a new key-value pair even if the key already exists in the multimap, while in map, the insert() function will not insert a new key-value pair if the key already exists in the map and will return an iterator pointing to the existing key-value pair.
    //mpp[key] = value; //this syntax is not allowed in multimap as it does not allow for duplicate keys, so we cannot use this syntax to insert key-value pairs into a multimap, we have to use the insert() function to insert key-value pairs into a multimap.
    //So what we do when we want to call a pair with a key in multimap is we use the find() function to find the range of key-value pairs with the given key, and then we can iterate through that range to access the values associated with that key.
    //functions in multimap: insert(), erase(), find(), count(), empty(), size()
}

void UnorderedMap(){
    //basically unique keys but unsorted, so it does not maintain any order among the keys, but it allows for fast access to the values associated with the keys using a hash function to map the keys to their corresponding values.
    //generally complexity is O(1) for insert(), erase(), find(), and count() functions, but in worst case when there are many collisions, the complexity can degrade to O(n) as it may have to traverse the entire bucket to find the key-value pair.
    //unordered_map is a data structure that stores key-value pairs in an unordered manner, where the keys are not ordered based on their value, but rather based on their hash value.
    //lower_bound() and upper_bound() functions are not available in unordered_map as it does not maintain any order among the keys, so we cannot use these functions to find the range of key-value pairs in an unordered_map.
    //all functions are similar to map, but the key-value pairs are stored in an unordered manner, so the time complexity of the functions may vary based on the hash function used and the number of collisions in the unordered_map.
    //functions in unordered_map: insert(), erase(), find(), count(), empty(), size()
    //it has better complexity for insert(), erase(), find(), and count() functions compared to map, as it uses a hash table to store the key-value pairs, which allows for average case O(1) time complexity for these functions, while map has O(log n) time complexity for these functions as it uses a balanced binary search tree to store the key-value pairs.
    //For most cases complexity remains O(1) for unordered_map, but in worst case when there are many collisions, the complexity can degrade to O(n) as it may have to traverse the entire bucket to find the key-value pair.
}

int main(){
    int a;
    cin >> a;
    print(a);
    // explainPair();
    // explainVector();
    // explainList();
    // explainDeque();
    // explainStack();
    // explainQueue();
    // explainPrioeityQueue();  
    // explainSet();
    // explainMultiSet();
    // explainUSet();
    // explainMap();
    // explainMultiMap();
    // explainUnorderedMap();
}