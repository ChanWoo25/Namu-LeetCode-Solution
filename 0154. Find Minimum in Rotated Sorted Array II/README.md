## 154. Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

```
Input: [1,3,5]
Output: 1
```
Example 2:

```
Input: [2,2,2,0,1]
Output: 0
```
Note:

## Solution

Hi everyone, Here's my Solution.

We keep one invariant
* All elements to the left of `nums[lo]` are not minimum
* and they're **equal to** or **less than** `nums[lo]`

In order to keep that constraint, we use inner while loop and `if(nums[lo] < nums[hi])` condition.

And under these constraint,
* If we found `nums[lo+1]` smaller than `nums[lo]`, index `lo+1` should be pivot and a minimum value we want.
* Also, If `nums[lo] < nums[hi]`, we can notice that the sub-array from `lo` to `hi` is in ascending order. So we'll take nums[lo] as answer.

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums[0];

        if(nums[0] < nums[n-1])
            return nums[0];

        int lo(0), hi(n-1);
        while(lo < hi)
        {
            while(lo < hi && nums[lo] == nums[lo+1])
                lo++;
            if(lo < hi && nums[lo] > nums[lo+1])
                return nums[lo+1];
            else if(nums[lo] < nums[hi])
                return nums[lo];
            else
            {
                int m = (lo+hi)/2;
                if(nums[lo] < nums[m])
                    lo = m + 1;
                else
                    hi = m;
            }
        }

        return nums[lo];
    }
};
```
