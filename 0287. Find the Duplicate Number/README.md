## 0287. Find the Duplicate Number

### Description
Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only one repeated number in `nums`, return this repeated number.

#### Constraints:
- 2 <= n <= 3e4
- nums.length == n + 1
- 1 <= nums[i] <= n
- All the integers in nums appear only once except for precisely one integer which appears two or more times.
 
#### Follow-Up:
- How can we prove that at least one duplicate number must exist in nums?
- Can you solve the problem without modifying the array nums?
- Can you solve the problem using only constant, O(1) extra space?
- Can you solve the problem with runtime complexity less than O(n2)?

---------------------------------------
### Try 1
- 가장 쉽게 떠올릴 수 있는 해법
- sorting 후, Linear하게 탐색.
- No extra mem.
> Time Complexity : O(NlgN + N)\
  Space Complexity : O(1)

> **Runtime**: 8 ms, faster than 92.62% \
  **Memory Usage**: 11 MB, less than 82.26% \
  의외로 좋은 성적
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); // [1, n-1]
        sort(nums.begin(), nums.end());
        
        int i=-1;
        while( ++i < n-1)
        {
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        
        return -1;
    }
};
```

### Try 2
- `unorderd_map<int, `bool>을 이용
- nums의 원소를 Map에 집어넣으면서 즉시 탐색
> Time Complexity : average O(N)\
  Space Complexity : O(1)

> Runtime: 12 ms, faster than 76.91% \
Memory Usage: 12.6 MB, less than 19.52%  \
예상보다 퍼포먼스는 떨어지고 예상대로 메모리는 더 차지.

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> uMap;
        for(auto& x: nums)
        {
            if(uMap.find(x) == uMap.end())
                uMap[x] = true;
            else
                return x;
        }
        return -1;
    }
};
```

### Try 3
- uMap의 find를 쓰지 않고, `uMap<int, int>`을 완성한 뒤, 답을 탐색하는 방식
- 시간은 Try 2보다 빨랐고(Why?), 메모리는 확실히 더 잡아먹었다.
> Time Complexity : average O(N)\
  Space Complexity : O(1)
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> uMap;
        for(auto& x: nums)
            uMap[x]++;

        for(auto& x: nums)
        {
            if(uMap[x] > 1)
                return x;
        }

        return -1;
    }
};
```

### Ref 0
- 신박했던 풀이
- nums의 원소 범위가 [1, n]임을 이용한 풀이
  - nums[0]=1, nums[1]=2, nums[2]=3, ... 과 같이
  - 모든 원소가 하나씩 들어가 있는 이상적인 환경을 가정하고,
  - 이에 벗어난 원소를 탐색하는 풀이
- `while (A[i] != i+1 && A[i] != A[A[i]-1])`
  - `A[i] = i+1`을 만족하지 않고,
  - `A[i]-1` 이 가리키는 곳에 `A[i]`가 응당 들어있지 않은 경우
  - swap 하여 원소가 있어야 하는 자리에 배치되도록 하고,
  - 존재하지 않는 원소는, 배열 내에 중복되어 있는 바로 그 원소가 들어있게 된다.
- **Time & Space Complexity에 있어서 최고.**
> Time Complexity : worst O(N + N)\
  Space Complexity : O(1)

```cpp
class Solution {
public:
    // 287. Find the Duplicate Number
    // 将数字x交换到索引位置x的地方，每次都可以安顿好一个数字，最后那个无法安顿的就是重复的（只有一个）
    int findDuplicate(vector<int>& A) {
        int n = A.size();

        for (int i = 0; i < A.size(); ++i) {
            while (A[i] != i+1 && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            }
        }

        // for(auto a: A) cout << a << " ";
        // cout << endl;

        for (int i = 1; i < A.size(); ++i) 
            if (i != A[i]) 
                return A[i];
        
        return -1;
    }
};
```
---
- 아래와 같이 nums가 될 수 있는 모든 원소를 벡터로 관리할 수도 있지만, 이는 nums의 range가 커지게 되면, bit hash map정도로는 커버가 안될만큼 혹은 바람직하지 않은 메모리를 차지할 수 있다. General하게는 unordered_map이 좋아보인다.
- 특히 기존의 배열을 유지하고 어느 정도의 추가 메모리를 용납한다면, 더욱 unorderd_map이 이상적일 것이고, 만약 unorderd_map의 장점을 취할 수 있는 한도를 넘어선 Range라면, 조금더 시간이 걸리더라도 map을 사용하면 되겠다.
- 에버노트 (map과 unorderd_map의 차이)[https://www.evernote.com/shard/s499/nl/185900599/4f7a7b24-feee-2b4f-74f4-85e401e78476?title=%5B%ED%95%9C%EC%96%91%EB%8C%80%ED%95%99%EC%9B%90%5D%20%EB%A9%B4%EC%A0%91%20%EC%A4%80%EB%B9%84]

### Ref 1

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        vector<bool> visited(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            if(visited[nums[i]]==true){
                return nums[i];
            }
            visited[nums[i]] = true;
        }
        return 0;
    }
};
```

### Ref 2 

```c
/* get the index and bit */
void getindexandbit(int val, int *index, int *bit)
{
    *index = val / 32;
    *bit =   val % 32;
    return;
}

int findDuplicate(int* nums, int numsSize){
    unsigned int *hasharray = malloc(sizeof(int) * 1000);
    unsigned int mask = 0;
    int i = 0;
    for(i = 0; i < 1000; i++)
    {
        hasharray[i] = 0;
    }
    
    for( i = 0; i < numsSize; i++)
    {
      int index = 0;
      int bit = 0;
      getindexandbit(nums[i], &index, &bit);
      
      if (bit < 31)
       mask = 1 << (bit);  
      else
        mask = 0x80000000;      
      if (hasharray[index] & mask)
      {
          break;
      }
      else
      {
         hasharray[index] = hasharray[index] | mask; 
      }
    }
    return nums[i];    
}
```