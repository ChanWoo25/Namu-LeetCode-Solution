## 300. Longest Increasing Subsequence

### Description
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

#### Note:
1. 
#### Follow-Up:
1. 

### Ref (Dynamic Programming with Binary Search)
- [**Very Helpful Article**](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)
- 위 Article을 참고했을 때, `ans`는 각 **Active Lists**의 **End element**를 가지고 있는 Vector로 볼 수 있다.
- 우리의 목적은 완전한 Longest Increasing Subsequence(LIS)를 찾는 것이 아니기 때문에 End element만을 가지고 최대 length를 구한다.
- **Main strategy**
  1. If `nums[i]` is smallest among all end candidates of active lists, we will start new active list of length 1.
  2. If `nums[i]` is largest among all end candidates of active lists, we will clone the largest active list, and extend it by `nums[i]`.
  3. If `nums[i]` is in between, we will find a list with largest end element that is smaller than `nums[i]`. Clone and extend this list by `nums[i]`. We will discard all other lists of same length as that of this modified list.
> Time Complexity : O(NlgN)\
  Space Complexity : O(N) for `ans`

> Runtime: 8 ms \
  Memory Usage: 10.5 MB
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, prev;

        for(int i=0; i<n; i++)
        {   // Binary Search
            // Sorted array인 ans 안에서 
            // nums[i] 보다 크거나 같은 첫번째 원소를 찾는다.
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);

            // 만약 찾지 못했다면, it는 검사된 elem중 가장 큰 원소이므로 ans에 포함될 자격이 있다.
            // 고로 끝에 집어넣는다.
            if(it == ans.end())
            {
                ans.push_back(nums[i]);
                prev.
            }
            // 만약 *it와 nums[i] 같다면 달라지는 것은 아무것도 없다.
            // 눈여겨 볼 것은 *it가 nums[i]보다 클 때이다.
            // 설령 nums[i]가 최종 LIS에 포함되지 않더라도 *it자리에 
            // 보다 더 작은 nums[i]가 들어있을 때, 이후 더 큰 원소를 집어넣기 유리해진다.
            // 이렇게 진행할 시, 최종 LIS는 우리가 원하는 배열이 아니겠지만, 
            // 우리가 원하는 것은 길이 뿐이므로 목적을 달성하는 것이 가능하다.
            else
                *it = nums[i];
        }

        return ans.size();
    }
};
```

- Get LIS version
- Time complexity O(NlgN)
- Space(3N) for `tail, prev, stk` each takes N
```cpp
int getLIS(vector<int>& nums)
{
    vector<int> tail;
    vector<int> prev(nums.size());
    int last = -1;
    for(int i=0; i<nums.size(); i++)
    {
        auto it = lower_bound(tail.begin(), tail.end(), nums[i], \
            [&nums](int x, int y){
                return nums[x] < y;
            });
        if(it == tail.end())
        {
            prev[i] = (tail.empty()) ? (-1) : tail.back();
            last = i;
            tail.push_back(i);
        }
        else
        {
            prev[i] = (it == tail.begin()) ? (-1) : *(it-1);
            *it = i;
        }
    }

    stack<int> stk; // Last In, First Out
    while(last != -1)
    {
        stk.push(nums[last]);
        last = prev[last];
    }

    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }   cout << endl;

    return tail.size();
}
```

### Ref 2 (only DP)
- 배열을 따로 관리하지는 않지만, `nums`의 원소를 비교해가며 해당 인덱스에서 최대 Length를 구하는 DP풀이
> Runtime: 388 ms, faster than 12.67% \
Memory Usage: 10.7 MB, less than 67.51% 
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans(1);
        vector<int> DP(n, 0);
        
        DP[0] = 1;
        for(int i=1; i<n; i++)
        {
            int maxLen(0);
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i])
                    maxLen = (maxLen>DP[j])?maxLen:DP[j];
            }
            DP[i] = maxLen + 1;
            ans = (ans>DP[i])?ans:DP[i];
        }
        return ans;
    }
};
```