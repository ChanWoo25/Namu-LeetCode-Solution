## 1751. Maximum Number of Events That Can Be Attended II

### Description

You are given an array of `events` where `events[i] = [startDayi, endDayi, valuei]`. The `ith` event starts at `startDayi` and ends at `endDayi`, and if you attend this event, you will receive a value of `valuei`. You are also given an integer `k` which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return **the maximum sum of values** that you can receive by attending events.


#### Constraint:
- `1 <= k <= events.length`
- `1 <= k * events.length <= 106`
- `1 <= startDayi <= endDayi <= 109`
- `1 <= valuei <= 106`
  
#### Note:
- startDat와 endDay의 Range가 너무 커서 Dynamic programming이 힘들어보임.
- 
#### Follow-Up:

---------------------------------------
### Try [Fail]
- 최대 k개의 Event에서 최대의 Value를 얻어야 한다.
- k개의 제한이 없다면, Greedy하게 푸는게 정석
- NlgN정도의 시간 복잡도를 확보해야할 듯으로 보임


### Ref 1 - DP without memization
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp
class Solution {
private:
    int n;

    int solve(const vector<vector<int>>& events, int pos, int k)
    {
        if(pos >= n || k == 0)
            return 0;
        
        // Find 'the next-event' that we can take
        unsigned i; 
        for(i = pos + 1; i < n; i++)
            if(events[pos][1] < events[i][0])
                break;

        return max(\
            // Case 1 : Not take current event.
            solve(events, pos + 1, k),                  
            // Case 2 : Take current event and Check Next possible event.
            events[pos][2] + solve(events, i, k - 1));  
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());

        return solve(events, 0, k);
    }
};
```

### Ref 2 - Advanced
1. Memoization
2. Optimize "Finding Next Event" process
  
> Time Complexity : O(N)\
  Space Complexity : O(1)
```cpp
class Solution {
private:
    int n;
    int j=0;
    // dp[pos][k] == pos 인덱스까지 검사했고, k개의 잔여 Event가 남아있을 때의 최대 Value
    vector<vector<int>> dp; 

    int solve(const vector<vector<int>>& events, int pos, int k)
    {
        cout <<"#"<< j++ << endl;

        if(pos >= n || k == 0)
            return 0;
        
        int& x = dp[pos][k];
        if(x != -1){
            cout << x << endl;
            return x;
        }

        // Find 'the next-event' that we can take
        int i = upper_bound(events.begin(), events.end(), 
            vector<int>{events[pos][1], INT32_MAX, INT32_MAX}) - events.begin();
        cout << "i: " << i << endl;
        return x = max(\
            // Case 1 : Not take current event.
            solve(events, pos + 1, k),                  
            // Case 2 : Take current event and Check Next possible event.
            events[pos][2] + solve(events, i, k - 1));  
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());

        dp.assign(n + 1, vector<int>(k+1, -1));

        return solve(events, 0, k);
    }
};

```