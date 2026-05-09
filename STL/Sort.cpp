# include <bits/stdc++.h>
usning namespace std;

bool comp(pair<int,int> a, pair<int,int> b) { //comp tells us if the two elements are in correct order or not
    if (a.second < b.second) return true;
    if (a.second > b.second) return false;
    if (a.second == b.second) {
        if (a.first >= b.first) return true;
        else return false;
    }
}

void explainSort() {
    sort(a ,a+n); // O(nlogn)
    sort(v.begin(), v.end()); // O(nlogn)

    sort(a, a+n, greater<int>()); // O(nlogn) in decreasing order

    pair <int,int> a[] = {{1,2}, {2,1}, {4,1}};

    //sort it according to second element of pair
    //if second element is same then sort according to first element but in descending order

    sort(a,a+n,comp); //comp is a self written boolean function

    int num = 7;
    int cnt = __builtin_popcount(num); //counts the number of set bits in the binary representation of num

    long long num = 123456789012345;
    int cnt = __builtin_popcountll(num); //counts the number of set bits in the binary representation of num for long long type

    string s = 123;
    sort(s.begin(), s.end()); //sorts the string in lexicographical order
    do{
        cout << s << endl;
    }while (next_permutation(s.begin(), s.end())); //generates the next lexicographical permutation of the string s and returns true if such a permutation exists, otherwise returns false
    //next permutation has a drawback that it generates the permutations in lexicographical order, so if we want to generate all permutations in a different order, we can use prev_permutation function which generates the previous lexicographical permutation of the string s and returns true if such a permutation exists, otherwise returns false
    //for example if the string is 231, the next permutation will be 312 and the previous permutation will be 213 and then the next permutation will be 321 and it will stop there as it moves in dictioanary order
    //So it is needed to sort the string before using next_permutation function to generate all permutations in lexicographical order
    int maxi = *max_element(a, a+n); //returns the maximum element in the array a
    int mini = *min_element(a, a+n); //returns the minimum element in the array a
}