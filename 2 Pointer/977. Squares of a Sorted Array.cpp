/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/



class Solution {
public:

    vector<int> merge(vector<int>& pos, vector<int>& neg){
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i < pos.size() && j < neg.size()){
            if(pos[i] <= neg[j]){
                res.push_back(pos[i]);
                i++;
            }
            else{
                res.push_back(neg[j]);
                j++;
            }
        }
        while( i < pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        while( j < neg.size()){
            res.push_back(neg[j]);
            j++;
        }
        return res;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int>pos;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                int sq = nums[i] * nums[i];
                neg.insert(neg.begin(),sq);
            }
            else{
                int sq = nums[i] * nums[i];
                pos.push_back(sq);
            }
        }
        if(pos.size() == 0){
            return neg;
        }
        if(neg.size() == 0){
            return pos;
        }

        nums = merge(pos,neg);
        return nums;
    }
};