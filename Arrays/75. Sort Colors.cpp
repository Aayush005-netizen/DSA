/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/




class Solution {
public:
    void sortColors(vector<int>& nums) { // red , blue , green  =====>>>>>> red->000000000 blue->111111111 green ->22222222
        int high = nums.size() - 1; // 0 - red-1 = 0 ; green+1 - n-1 = 2 
        int low = 0;
        int mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
                //after this iteration mid can be any so we have to categorize it accordingly for example if haigh had 0 then mid becomes 0 so we analyze it again and then categorize it accordingly
            }
        }
    }
};