/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100*/




class Solution {
public:
    bool check(vector<int>& nums) {
        int v = nums.size();
        
        // A sorted+rotated array can have at most 1 drop
        // (a point where a larger element is followed by a smaller one)
        // Example: [3,4,5,1,2] → only one drop at 5→1
        int drops = 0;

        // Step 1: Count drops in the array
        for(int i = 1; i < v; i++){
            if(nums[i] < nums[i-1]) drops++;
        }

        // Step 2: Check wrap around (last element → first element)
        // Because array is circular, last connects back to first
        // If last > first, that's another drop
        if(nums[v-1] > nums[0]) drops++;

        // Step 3: If drops <= 1, array is sorted+rotated (or just sorted)
        return drops <= 1;
    }
};