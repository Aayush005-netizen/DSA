/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;
        for(int i  = 0 ; i < nums.size() ; i++ ){
            if(count == 0){element = nums[i];
            count=1;}
            else{
                if(nums[i] == element){count++;}
                else{count--;}
            }
        }
        return element;
    }
};




/*
## Boyer-Moore Voting Algorithm

### Core Idea
Majority element (appearing **> n/2 times**) will always **survive cancellation** against all other elements combined.

---

### Mental Model
Think of it as an **election with fights**:
- Every soldier fights an enemy soldier and **both die**
- The army with > half the soldiers **always has survivors**
- The last soldier standing = majority element

---

### How it works

**Two variables:**
- `candidate` → current "potential" majority
- `count` → candidate's "strength"

**Logic:**
```
count == 0      → pick new candidate, count = 1
nums[i] == candidate → count++   (ally found, strengthen)
nums[i] != candidate → count--   (enemy found, cancel out)
```

---

### Why it's guaranteed to work
- Majority element appears **> n/2 times**
- All other elements combined appear **< n/2 times**
- So majority can be cancelled **at most** (n/2 - 1) times
- It **always has votes left** at the end

> ⚠️ Only works when majority is **guaranteed to exist**. If not, add a second pass to verify the candidate's actual count.

---

### Complexity
| | |
|---|---|
| Time | O(n) — single pass |
| Space | O(1) — no extra array |
*/