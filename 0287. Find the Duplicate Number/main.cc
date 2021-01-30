#include "../libs.hpp"


// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, bool> uMap;
//         for(auto& x: nums)
//             uMap[x] = true;
        

//         for(auto& x: nums)
//         {
//             if(uMap[x])
//                 return x;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    // 287. Find the Duplicate Number
    // 将数字x交换到索引位置x的地方，每次都可以安顿好一个数字，最后那个无法安顿的就是重复的（只有一个）
    int findDuplicate(vector<int>& A) {
        int n = A.size();

        for (int i = 0; i < A.size(); ++i) {
            while (A[i] != i+1 && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            }
        }

        // for(auto a: A) cout << a << " ";
        // cout << endl;

        for (int i = 1; i < A.size(); ++i) 
            if (i != A[i]) 
                return A[i];
        
        return -1;
    }
};

int main()
{
    vi input = {1,3,2,2, 7, 2,5,2};
    Solution S;
    cout << S.findDuplicate(input) << endl;
    
    return 0;
}