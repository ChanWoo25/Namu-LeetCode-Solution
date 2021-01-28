## 0350. Intersection of Two Arrays II

### Description

Given two arrays, write a function to compute their intersection.

Example 1:

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
```
Example 2:
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
```

#### Note:
1. Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

#### Follow up:

1. What if the given array is already sorted? How would you optimize your algorithm?
2. What if nums1's size is small compared to nums2's size? Which algorithm is better?
    - *hash map을 사용하는 경우, 더 작은 배열을 이용하여 map을 생성하여 더 적은 메모리를 사용하고자 하는 전략을 고려할 수 있다.*
3. What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
    - *Case1: 두 배열 중 크기가 작은 배열은 메모리에 충분히 들어가는 경우, Hash Map을 만들고 크기가 큰 배열을 여분의 메모리에 넣을 수 있는 만큼씩 불러와서 Hash Map과 비교하며 답을 찾을 수 있다.*
    - *Case2: 두 배열 중 어느 것도 Hash Map으로 한번에 메모리에서 관리할 수 없는 경우, Hash Map을 활용하는 것은 포기하고, 디스크에 저장되어 있는 배열을 Externel Merge Sort등을 활용하여 재정렬한 뒤, two-pointer-method로 답을 찾아낼 수 있을 것이다.*
---
### Try 1
- 349번을 hash_map을 사용하여 해결했듯이, 마찬가지로 임의의 Key값에 대해서 Constant average time으로 접근할 수 있는 unordered_map을 사용하여 해결하였다.

>   Time Complexity : $O(n1 + n2)$ \
    Space Complexity : $O(min(n1, n2))$

> **Runtime**: 4 ms, faster than 97.26% of C++ online submissions for Intersection of Two Arrays II. \
**Memory Usage**: 10.4 MB, less than 88.86% of C++ online submissions for Intersection of Two Arrays II.

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int  n1_size(nums1.size()), n2_size(nums2.size());
        vector<int> ans;
        if(n1_size == 0 || n2_size == 0)
            return ans;

        if(n1_size > n2_size)
            swap(nums1, nums2);

        unordered_map<int, int> Map;
        for(int& x: nums1)
            Map[x]++;

        // for( const auto& [key, value] : Map )
        //     cout << "Key:[" << key << "] Value:[" << value << "]" << endl;
        

        for(int& y: nums2)
        {
            if(Map.find(y) != Map.end() && Map[y] > 0)
            {
                --Map[y];
                ans.push_back(y);
            }
        }

        return ans;
    }
};
```

### Try 2
- 이 접근법의 경우, 시간 복잡도는 Sorting에 Dominant하다.
- Try1에 비해 시간이 더 걸리지만, **Space Complexity를 확연히 절감**할 수 있다는 장점이 있다.
- Follow-Up 1번의 경우, 아래 코드의 첫 두줄을 소거함으로써 이 알고리즘의 큰 비중을 차지하는 Sorting을 제거할 수 있게 된다. 이는 훨씬 뛰어난 수행속도를 내게 하며, 주어진 문제에 가장 Optimal한 풀이라고 할 수 있다.
> Time Complexity : $O(n_{1}lgn_{1} + n_{2}lgn_{2})$\
  Space Complexity : $O(1)$
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int _i1(0), _i2(0), x, y;
        vector<int> ans;
        while(_i1 < nums1.size() && _i2 < nums2.size())
        {
            x = nums1[_i1], y = nums2[_i2];
            if(x == y)
                ans.push_back(x), _i1++, _i2++;
            else if(x < y)
                _i1++;
            else // if(y < x)
                _i2++;
        }
        
        return ans;
    }
};
```