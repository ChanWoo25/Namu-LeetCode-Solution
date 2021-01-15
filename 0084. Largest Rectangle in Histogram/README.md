### Sol 1 [C++] - Using Left and Right Array

- Time: O(N2+N) 
- Space: O(2N)
- `heights[i]`의 높이를 적용할 수 있는 최대, 최소 인덱스를 모두 구해놓고
  Max Area를 손쉽게 구하는 풀이.

```cpp
class Solution { 
public: 
    int largestRectangleArea(vector<int>& heights) { 
         
        if(heights.empty())  
            return 0; 
        int n = heights.size(); 
         
        vector<int> left(n), right(n); 
        left[0] = -1; 
        right[n - 1] = n; 
         
        for(int i = 1; i < n; i++) 
        { 
            int ptr_l = i - 1; 
            while(ptr_l >= 0 && heights[ptr_l] >= heights[i]) 
                ptr_l = left[ptr_l]; 
            left[i] = ptr_l; // DP도 살짝 섞인 느낌. 
        } 
         
        for(int i = n - 2; i >= 0; i--)  
        { 
            int ptr_r = i + 1; 
            while(ptr_r < n && heights[ptr_r] >= heights[i]) 
                ptr_r = right[ptr_r]; 
            right[i] = ptr_r; // DP도 살짝 섞인 느낌. 
        } 
         
        int ret = 0; 
        for(int i = 0; i < n; i++) 
            ret = max(ret, heights[i] * (right[i] - left[i] - 1)); 
         
        return ret; 
    } 
};
```

### Sol 2 [C++] - Using Stack

- Time: O(N2+N) 
- Space: O(2N)
1. i-th height가 Stack의 가장 위 원소보다 크거나 으면 Stack에 추가한다.
2. 만약 작으면, i-th height가 Stack의 가장 위 원소보다 크거나 같아질 때까지 다음을 수행한다.
	1. Stack의 top원소에 해당하는 높이가 H라고 하자.
	2. Stack은 크거나 같은 높이의 원소만을 쌓아올렸으므로,
	3. 최소 H의 높이로 구할 수 있는 너비는 (i - top원소의 인덱스) 일 것이다.
	   [top보다 이전 인덱스는 H보다 낮은 높이일 수 있고, 이후 i-th까지 H보다 높은 원소만 등장했기 때문에 높이 H인 top원소가 아직 Stack에 남아있는 것이다.]
	4. 넓이를 구해 max값보다 크면 답을 갱신한다.
3. 2-(1~4)를 while문이 멈출때까지(i를 [0, n-1]까지 검사 + 스택 모두 비워짐 heights[n]==0인데, Stack이 비지 않는 이상 항상 else문이 실행되겠지?), 즉 모든 가능한 직사각형 넓이를 검사할 때까지 반복한다.

```cpp
typedef pair<int, int> pii; 
class Solution { 
public: 
    int largestRectangleArea(vector<int>& heights)  
    {   // 검사 종료 지점 추가. 
        heights.emplace_back(0); 
        int n = heights.size(); 
         
        stack<int> Stack; 
        int i=0, maxArea(0); 
        while(i < n) 
        {   // Stack은 해당 원소가 가리키는 Height를  
            // 더 이상 적용하지 못하게 될 때, Stack에서 빠져나온다. 
            if(Stack.empty() || heights[Stack.top()] <= heights[i]) 
                Stack.push(i++); 
            else 
            {    
                int h = heights[Stack.top()]; Stack.pop(); 
                int w = Stack.empty()?(i):(i - (Stack.top()+1)); 
                maxArea = max(maxArea, h*w); 
            } 
        } 
         
        return maxArea; 
    } 
};
```