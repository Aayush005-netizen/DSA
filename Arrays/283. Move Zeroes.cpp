/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] == 0){
                int z = i;
                for(int j = z+1; j < size; j++){
                    if(nums[j] != 0){
                        nums[z] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
                if (nums[z] == 0){
                    break;
                }
            }
        }
    }
};