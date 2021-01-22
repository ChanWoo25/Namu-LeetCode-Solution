### 

**Time Complexity** : $O(1)$

**Space Complexity** : $O(1)$

**Description**

#### Sol [C++] 
- 수식 바탕으로 풀이 O(1)
![My Solution](image.png)
```cpp
class Solution { 
public: 
    int reachNumber(int target) { 
        target = abs(target); 
        long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2); 
        long long sum = n * (n+1) / 2; 
        if (sum == target) return n; 
        long long res = sum - target; 
        if ((res&1) == 0)  
            return n; 
        else  
            return n+((n&1) ? 2 : 1); 
         
    } 
};
```

#### Sol [py3]

- 위와 방식을 동일하지만 k를 수식을 이용해서가 아닌 반복문으로 탐색하는 방법.
```python
class Solution(object): 
    def reachNumber(self, target): 
        target = abs(target) 
        k = 0 
        while target > 0: 
            k += 1 
            target -= k 
        return k if target % 2 == 0 else k + 1 + k%2
```