/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

*/


/*
Pascal value of an element is (row - 1)C(col - 1)
No. of col is equal to row;
i.e. 6th row will have 6 columns
in a row 

in 6th row : [1,5,10,10,5,1]

first element is 1 always : current  = 1 : [1]
second element : (1 * 5)/1 : (current * (row - col))/col : [1,5]
third element : (5 * 4)/2 : (current * (row - col))/col : [1,5,10]
fourth element : (10 * 3)/3 : (current * (row - col))/col : [1,5,10,10]
fifth element : (10 * 2)/4 : (current * (row - col))/col : [1,5,10,10,5]
sixth element : (5 * 1)/5 : (current * (row - col))/col : [1,5,10,10,5,1]

*/


class Solution {
public:

    vector<int> generate_row(int row){
        long long ans = 1;
        vector <int> res;
        res.emplace_back(ans);
        for(int i = 1; i < row; i++){ //Finding Pascal Value
            ans = ans * (row - i);
            ans = ans / i;
            res.emplace_back(ans);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1; i <= numRows; i++){
            res.emplace_back(generate_row(i));
        }
        return res;
    }
};
