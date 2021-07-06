### 

**Time Complexity** : *O(N)*

**Space Complexity** : *O(1)*

**Description**

- SubArray's sum을 다루는 문제는 언제나 [0, i] 구간의 합을 갖는 SUMs array를 만들고 시작하는게 편하다.
- 구하고자 하는 것은 $sum \geq s$인 최소 길이의 Sub-arr.
  
#### try1 (Two-pointer)
1. linear하게 `nums[0]`부터 시작하여 $sum \geq s$를 만족하는 최소 길이를 찾는다.
2. 그 이후 two-pointer 방식으로 배열 끝까지 탐색해 나가면서 최소 길이를 찾는다.
3. SUMs 배열을 만드는 데에 $O(N)$ 소요, two pointer 방식의 Worst case $O(2N)$
4. Exception
   1. if nums size is 0, there's no sub-array.
   2. if `sums[n]`(=all elements' sum) is less than s, there is no sub-array.

#### try2 (+ Binary Search)
1. 처음 $sum \geq s$를 만족하는 최소 길이를 찾을 때 Binary Search를 활용할 수 있다.
2. 또한 p2를 늘려갈 때마다 p1을 찾아야 하는데, 이 과정 또한  BS로 구현할 수 있다. 만약의 배열의 크기가 커지면 도움이 될 것.

#### try3 (NO Sums array for O(1) Space complexity and O(N) Time) 
- 결과적으로 제일 빨랐다. **N개의 Sum Array를 만들 필요가 없는 부분**에서 부터 차이가 많이 벌어질 듯 하다.

```cpp
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int n = nums.size(), sum(0);
        if(n == 0)
            return 0;

        vector<int> sums(n+1, 0);

        for(int i=1; i<=n; i++)
            sums[i] = (sum += nums[i-1]);
        
        if(sums[n] < s)
            return 0;

        int p1(0), p2(1);
        while(sums[p2] < s) 
            p2++;

        int minLen(p2);
        do{
            while(sums[p2] - sums[p1+1] >= s) 
                p1++;
            minLen = (minLen < p2-p1)? minLen : (p2-p1);
        } while(++p2 <= n);
        
        return minLen;
    }
};


class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int n = nums.size(), sum(0);
        if(n == 0)
            return 0;

        vector<int> sums(n+1, 0);

        for(int i=1; i<=n; i++)
            sums[i] = (sum += nums[i-1]);
        
        if(sums[n] < s)
            return 0;

        int p1(0), p2;
        {   // Binary Search to find First Sub-array.
            int lo(1), hi(n);
            while(lo < hi)
            {
                int m = (lo+hi)/2;
                if(sums[m] < s)
                    lo = m+1;
                else
                    hi = m;
            }
            p2 = (lo+hi)/2;
        }

        int minLen(p2);
        do{
            {   // Binary Search to find p1 position for minimum length.
                int lo(p1), hi(p2), p2sum(sums[p2]);
                while(lo < hi)
                {   
                    int m = (lo+hi)/2;
                    if(p2sum - sums[m] >= s)
                        lo = m + 1;
                    else
                        hi = m;
                }
                p1 = lo - 1; 
            }
            minLen = (minLen < p2-p1)? minLen : (p2-p1);
        } while(++p2 <= n);

        return minLen;
    }
};

class Solution3 {
public:
    int minSubArrayLen(int s, vector<int>& A) {
        int i = 0, n = A.size(), res = n + 1;
        for (int j = 0; j < n; ++j) {
            s -= A[j];
            while (s <= 0) {
                res = min(res, j - i + 1);
                s += A[i++];
            }
        }
        return res % (n + 1);
    }
};
```