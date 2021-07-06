### Two Sum II - Input array is sorted.

**Time Complexity** : *O(NlgN)*

**Space Complexity** : *O(1)*

**Description**

- 합이 정확히 `target` 이 되는 두 원소를 찾아야 하기 때문에 O(lgN)으로 풀이하는 법은 없어 보인다.
- 두 원소를 i1, i2 변수로 탐색해나갈 때, i1을 고정시켜두고, 남아있는 원소 중에서 i2를 Binary Search로 탐색하면, 
- Brute Force로 탐색하는 경우 O(1/2*N^2) 보다 빠르게 O(NlgN)으로 해결할 수 있다.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i1, t;
        for(i1 = 0; i1 < n-1; i1++)
        {
            t = target - numbers[i1];
            int l(i1+1), h(n-1), m;
            while(l <= h)
            {
                m = (l+h)/2;
                if(numbers[m] < t)
                    l = m+1;
                else if(t < numbers[m])
                    h = m - 1;
                else
                    return vector<int>{i1+1, m+1};
            }
        }   
        return vector<int>{'e', 'r', 'r'};
    }
};
```

- 2nd -- O(N) 풀이
- 이런 방식으로 어떻게 지나쳐 버린, `lo, hi` 인덱스에 해당하는 원소가 필요 없다고 보장할 수 없는지 고민이 되었다. 아래 **Good Explanation** 참조

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo(0), hi(numbers.size()-1), sum;
        while((sum = numbers[lo] + numbers[hi]) != target)
        {
            if(sum < target)    lo++;
            else                hi--;
        }
        return vector<int>{++lo, ++hi};
    }
};
```

### Good Explanation


For those of you who are wondering how this works, here is a quick explanation:

Each sum is characterized by two indices $(i, j)$, where $0 \leq i < j < n$ with n the length of the input array. If we were to compute them explicitly, we end up with an n-by-n matrix.

If the input array is not sorted, to search for the target, there is no good way but comparing it with elements from the above matrix one by one. This is the naive $O(N^{2})$ solution. Of course you can use a HashMap to memorize visited elements and cut down the time to O(n) so we have the classic space-time tradeoff.

Now if the input array is sorted, the n-by-n summation matrix will have the following properties:

Integers in each row are sorted in ascending order from left to right.
Integers in each column are sorted in ascending order from top to bottom.
To find the target, we do not have to scan the whole matrix now since it exhibits some partial order. We may start from the top-right (or bottom-left) corner, then proceed to the next row or previous column depending on the relationship between the matrix element and the target until either it is found or all rows and columns are exhausted. The key here is that we can get rid of a whole row or column due to the two properties of the matrix specified above.

If you have finished leetcode problem **["240. Search a 2D Matrix II"](https://leetcode.com/problems/search-a-2d-matrix-ii/)**, you will find that this is exactly the same problem, except now of the two indices, the first has to be smaller than the second. Time complexity for "leetcode 240" is O(m + n), while for this problem we have m = n, plus the indices constraint so the time complexity will be O(n). Also we do not need the HashMap now so space complexity will be O(1).

