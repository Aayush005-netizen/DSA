/*Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 

Constraints:

1 <= nums.length <= 104
1 <= nums[i] <= 105*/



class Solution {
public:

    int sum_needed_elements(int num){
        int count = 2;
        int result = 1 + num;
        for (int i = 2; i <= num/2; i++){
            if (num % i == 0){
                result = result + i;    
                count++;
            }
            if (count > 4){
                return 0;
            }
        }
        if (count == 4) {return result;}
        else return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for(auto it : nums){
            result = result + sum_needed_elements(it);
        }
        return result;   
    }
};