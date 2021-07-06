### 498. Diagonal Traverse

**Time Complexity** : *O(MN)*

**Space Complexity** : *O(1)*

**Description**
- 1st TRY
- Spcae Complexity -- O(2M*(M+N))
- Time Complexity -- O(M)
- 메모리와 시간 모두 낭비

```cpp
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) { 
    vector<int> ret; 
    // Exception Handling. 
    if(matrix.size() == 0) 
        return ret; 
    int m = matrix.size(), n = matrix[0].size(), tmp = 0; 
    vector<int> idxs(m, 0); 
    for(int &i : idxs) 
        i = (tmp--); 
     
    while(ret.size() < m*n) 
    { 
        for(int i=m-1; i>=0; i--) 
        { 
            int idx = idxs[i]; 
            if(idx >= 0 && idx < n) 
                ret.push_back(matrix[i][idx]); 
            ++idxs[i]; 
        } 
        for(int i=0; i<m; i++) 
        { 
            int idx = idxs[i]; 
            if(idx >= 0 && idx < n) 
                ret.push_back(matrix[i][idx]); 
            ++idxs[i]; 
        } 
    } 
    return ret; 
}
```


- 2nd TRY
- Spcae Complexity -- O(M*N)
- Time Complexity -- O(1)
- 조건문이 다소 많아도 이해 쉽고, 불필요한 비교는 소거함.

```cpp
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) { 
    vector<int> ret; 
    // Exception Handling. 
    if(matrix.size() == 0) 
        return ret; 
    int m = matrix.size(), n = matrix[0].size(); 
    int i = 0, j = 0; 
    // Goal Constraint 
    while((i+j) < (m+n-1)) 
    { 
        if((i+j)%2 == 0) 
        {   // Right-Up Direction 
            while(i >= 0 && j < n) 
                ret.push_back(matrix[i--][j++]); 
            i++, j--; 
             
            // Move to Next Diagonal. 
            if(j < n-1) j++; 
            else        i++; 
        } 
        else 
        {   // Left-Down Direction 
            while(i < m && j >= 0) 
                ret.push_back(matrix[i++][j--]); 
            i--, j++; 
             
            // Move to Next Diagonal. 
            if(i < m-1) i++; 
            else        j++; 
        } 
    } 
    return ret; 
}
```