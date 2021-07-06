### 0275. H-Index II

>Time Complexity : $O(log_{2}N)$ \
>Space Complexity : $O(1)$

**Description**

#### Try 1
- Description이 조금 이해하기 힘들었음.
- 문제는 non-integer citations array의 H-index를 찾는 것.
- 최소 `H`개의 citations 원소가 `citations[i] >= H` 이면 이 array의 H-index는 H일 수 있다. 그 중 최대값을 찾는 문제.
- 주어진 array는 정렬되어 있다고 했으므로 Binary Search를 이용
  - 최종적으로 (n-lo)는 최대 H-index, (n-hi)는 한 발 차이로 h-index가 되지 못하는 지점을 찾는다.
  - case 1 -- `citations[m] < n - m`이면, m 아래에서는 H-index를 만족시키지 못한다. 따라서 m+1 대입.
  - case 2 -- `citations[m] >= n - m`이면, m 부터는 H-index를 만족시킨다. 다만 우리는 최대값을 찾아야 하므로 m-1을 대입하여 탐색을 계속한다.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;

        int lo(0), hi(n-1), m;
        while(lo <= hi)
        {
            m = (lo+hi)>>1; // Bit operations save time.
            
            if(citations[m] < n - m)
                lo = m + 1;
            else // if(citations[m] >= n - m)
                hi = m - 1;
        }

        return n - lo;
    }
};
```
