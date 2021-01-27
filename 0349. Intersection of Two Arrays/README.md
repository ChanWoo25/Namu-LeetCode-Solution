### 350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.



>Time Complexity : $O(N)$ \
>Space Complexity : $O(1)$

**Description**

#### Try 1 (Success)
- nums1을 더 작은 크기의 배열로 고정한 뒤, $n_{1}*log_{2}{n_{2}}$ 풀이를 하려했지만, 두 배열 모두 다 정렬이 되어 있지 않은 상태였기 때문에 lgN2 시간 안에 찾을 수 없었다. 
- 만약 Linear하게 탐색을 한다면, $O(n_{1}*n_{2})$ 안에 답을 찾을 수 있다.

> Runtime: **16 ms, faster than 18.28%** of C++ online submissions for Intersection of Two Arrays. \
> Memory Usage: **10.5 MB, less than 79.54%** of C++ online submissions for Intersection of Two Arrays.
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1(nums1.size()), n2(nums2.size());
        if(n1 == 0 || n2 == 0) 
            return vector<int>();
        
        if(n1 > n2) 
            return intersection(nums2, nums1);

        set<int> Set;
        vector<int> ret;
        for(auto& x: nums1)
        {
            if(Set.find(x) == Set.end())
            {
                Set.insert(x);
                for(auto &y : nums2)
                    if(x == y)
                    {
                        ret.push_back(x);
                        break;
                    }
            }
            else
                continue;
        }
        return ret;
    }
};
```

#### Try 2 ()
- unordered_map을 사용하면 Set보다 빠르게 중복 검사를 진행하고, 답을 찾을 수 있다.
- 만약 배열의 크기가 작은 쪽을 Sorting 후, Binary Search를 이용한다면, 더 편할 수 있다.
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1(nums1.size()), n2(nums2.size());
        if(n1 == 0 || n2 == 0) 
            return vector<int>();
        
        if(n1 > n2) 
            return intersection(nums2, nums1);


        unordered_map<int, bool> chk;
        vector<int> ans;
        for(auto& x: nums1)
            chk[x] = false;
        
        for(auto y: nums2)
        {
            if(chk.find(y) != chk.end() && !chk[y])
            {
                chk[y] = true;
                ans.push_back(y);
            }
        }

        return ans;
    }
};
```