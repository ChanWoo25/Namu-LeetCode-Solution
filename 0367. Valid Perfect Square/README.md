## 367. Valid Perfect Square

### Description
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.


#### Constraint: `1 <= num <= 2^31 - 1`
#### Note:
#### Follow-Up:

---------------------------------------
### Try
- 간단한 Binary Search 문제
- 오버플로우 주의하고, 정수 [1, 2e31] 안에서 탐색하면, 31번 안에 답을 찾을 수 있다.

> Time Complexity : O(lgN)\
  Space Complexity : O(1)
```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long  lo = 1, \
                            hi = (1<<30) - 1, \
                            Num = static_cast<unsigned long long>(num), \
                            m, mm;

        while(lo <= hi)
        {
            m = lo + (hi-lo)/2;
            mm = m * m;

            if(mm < Num)
                lo = m + 1;
            else if(Num < mm)
                hi = m - 1;
            else 
                return true;
        }
        
        return false;
    }
};
```

### Try
- 
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp

```