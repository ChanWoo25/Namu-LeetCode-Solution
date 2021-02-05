## 315. Count of Smaller Numbers After Self

### Description
You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.


#### Constraint:
- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
#### Note:
#### Follow-Up:

---------------------------------------
### Try 1
- Brute Force로 O(N^2)
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp

```

### Try 2 (Using Merge Sort)
- Merge Sort를 잘 응용한 Case지만, 공간과 시간 복잡도 면에서 낭비가 심하다.
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp
class Solution {
public:
    vector<int> sol;

    void merge(vector<pair<int,int>> &a, vector<pair<int,int>> &tmp, int start,int mid,int end)
    {
        int i=start,j=mid+1, k=start;
        while(i<=mid && j<=end)
        {
            if(a[i].first<=a[j].first){
                sol[a[i].second] += ((j - 1) - mid);
                tmp[k++] = a[i++];
            }
            else
                tmp[k++] = a[j++];
        }

        while(i<=mid){
            sol[a[i].second] += ((j - 1) - mid);
            tmp[k++] = a[i++];
        }

        while(j <= end){
            tmp[k++] = a[j++];
        }

        for(k = start; k <= end; k++)
            a[k] = tmp[k];
    }
    
    void mergesort(vector<pair<int,int>> &a, vector<pair<int,int>> &tmp, int start,int end){
        if(start>=end) return;
        int mid = start+(end-start)/2;
        mergesort(a, tmp, start,mid);
        mergesort(a, tmp, mid+1,end);
        merge(a, tmp, start,mid,end);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n =nums.size();
        sol.resize(n,0);
        vector<pair<int,int>> idx;
        vector<pair<int,int>> tmp(n);

        for(int i=0;i<n;i++)
            idx.push_back({nums[i],i});
        
        mergesort(idx, tmp, 0,n-1);
        return sol;
    }
};
```


### Try 3 (Segment Tree)
- nums 원소 값의 Range가 크지 않고, nums의 Size의 Range가 더욱 크다.
- 때문에 각 원소 값에 대한 정보를 담은 Segment Tree를 만들어 Update & Query를 하는 것이 유용하다.
- Segment Tree 는 담당 구간안에 존재하는 Element의 수를 지닌다.
- ret[i] 는 nums[i]보다 오른쪽에 존재하는 nums[i]보다 작은 원소들의 숫자이므로.
- nums[n-1]부터 Tree에 원소를 넣어나가며, [0,nums[i]-1]구간에 대한 원소의 갯수를 ret[i]에 넣으면 답을 구할 수 있다.
> Time Complexity : Update--O(lgN)O(N)  ||  Query--O(lgN) \
  Space Complexity : < O(4*mx)

> Runtime: 308 ms, faster than 12.86% \
Memory Usage: 87.4 MB, less than 10.19%
```cpp
class Solution {
private:
    vector<int> Tree;
    
    void Update(int s, int e, const int &x, int ti)
    {
        if(x < s || e < x)
            return;
        
        if(s == x && e == x){
            Tree[ti]++; return;
        }

        int m = s + (e-s)/2;
        Update(s, m, x, 2*ti);
        Update(m+1, e, x, 2*ti+1);
        Tree[ti] = Tree[2*ti] + Tree[2*ti+1];
    }
    
    int Query(int s, int e, const int& qs, const int& qe, int ti)
    {
        if(qs <= s && e <= qe)
            return Tree[ti];
        
        if(e < qs || qe < s)
            return 0;

        int m = s + (e-s)/2;
        return Query(s, m, qs, qe, 2*ti) + Query(m+1, e, qs, qe, 2*ti+1);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        // Compute nums' size and max value & 
        // Make range [0, min(2e4, mx)] 
        int n = nums.size(), mx(0);
        for(auto& x: nums) {
            x += 1e4;
            mx = (mx >= x) ? mx : x;
        }

        // Because element's range is [0, mx]
        int height = (int)(std::ceil(log2(mx)));
        int TreeSize = 2 * (int)pow(2, height) - 1; 
        Tree.assign(TreeSize, 0);

        // Compute Answer
        vector<int> ret(n);
        ret[n-1] = 0; Update(0, mx, nums[n-1], 1);
        for(int i = n - 2; i >= 0; i--)
        {
            ret[i] = Query(0, mx, 0, nums[i]-1, 1);
            Update(0, mx, nums[i], 1);
        }
        return ret;
    }
};
```


### Try 4 (Fenwick Tree)
- 
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp

```