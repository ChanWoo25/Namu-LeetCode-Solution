#include "../libs.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        vector<int> parent(nums.size());
        int last = -1;
        for (int i = 0; i<nums.size(); i++) {
            // lambda 식의 x는 res의 원소(0부터 대입), y는 nums[i], &nums로 nums의 reference넘겨줌.
            auto it = std::lower_bound(res.begin(), res.end(), nums[i], \
                [&nums](int x, int y) { return nums[x] < y; });

            if (it == res.end()) {
                parent[i] = (res.empty()) ? -1 : res.back();
                last = i;
                res.push_back(i);
            }
            else {
                parent[i] = (it == res.begin()) ? -1 : *(it - 1);
                *it = i;      
            }
        }

        int m = res.size();
        vector<int> lis(m);
        
        while (last != -1) {
            lis[--m] = nums[last];
            last = parent[last];
        }

        for(auto x: lis)
            cout << x << " ";
        cout << endl;

        return res.size();
    }
};

int getLIS(vector<int>& nums)
{
    vector<int> tail;
    vector<int> prev(nums.size());
    int last = -1;
    for(int i=0; i<nums.size(); i++)
    {
        auto it = lower_bound(tail.begin(), tail.end(), nums[i], \
            [&nums](int x, int y){
                return nums[x] < y;
            });
        if(it == tail.end())
        {
            prev[i] = (tail.empty()) ? (-1) : tail.back();
            last = i;
            tail.push_back(i);
        }
        else
        {
            prev[i] = (it == tail.begin()) ? (-1) : *(it-1);
            *it = i;
        }
    }

    stack<int> stk; // Last In, First Out
    while(last != -1)
    {
        stk.push(nums[last]);
        last = prev[last];
    }

    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }   cout << endl;

    return tail.size();
}

int main()
{
    vi input = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    Solution S;
    cout << getLIS(input) << endl;

    return 0;
}