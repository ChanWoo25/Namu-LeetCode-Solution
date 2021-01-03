#include "libs.hpp"

// class Solution {
// public:
//     int maximumUnits(vector< vector<int> >& boxTypes, int truckSize) {
//         sort(boxTypes.begin(), boxTypes.end(), \
//         [&](const vector<int>& a, const vector<int>& b){
//             if(a.back() > b.back()) return true;
//             else                    return false;
//         });

//         int ret(0);
//         for(int i=0; i<boxTypes.size(); i++)
//         {
//             int boxes = boxTypes[i].front();
//             int units = boxTypes[i].back();

//             if(boxes < truckSize)
//             {
//                 truckSize -= boxes;
//                 ret += boxes*units;
//             }
//             else
//             {
//                 ret += truckSize*units;
//                 break;
//             }
//         }

//         return ret;
//     }
// };

// class Solution {
// public:
//     map<int, int> mp;
//     int mod = 1e9 + 7;

//     unsigned nChoosek( unsigned n, unsigned k )
//     {
//         if (k > n) return 0;
//         if (k * 2 > n) k = n-k;
//         if (k == 0) return 1;

//         int result = n;
//         for( int i = 2; i <= k; ++i ) {
//             result = result * (n-i+1);
//             result /= i;
//         }
//         return result;
//     }

//     int countPairs(vector<int>& deliciousness) {
//         for(int& x: deliciousness)
//             mp[x]++;

//         vector<int> p2(22);
//         p2[0] = 1;
//         for(int i=1; i<=21; i++)
//             p2[i] = p2[i-1]*2;

//         long long ret(0);
//         for(auto it = mp.begin(); it != mp.end(); it++)
//         {
//             int k = it->first;
//             long long cnt = it->second;
//             int oth;

//             for(int i=0; i<= 21; i++)
//             {
//                 oth = p2[i] - k;
                
//                 if((oth >= 0) && (mp.find(oth) != mp.end())){
//                     if(mp[oth] == -1) 
//                         continue;
//                     if(oth == k)
//                         ret = (ret + (cnt * (cnt - 1) / 2)%mod) % mod;
//                     else
//                         ret = (ret + ((cnt * mp[oth])%mod)) % mod;
//                 } 
//             }

//             it->second = -1;
//         }
//         return ret;
//     }
// };

class Solution {
public:
    bool chk(const int& s1, const int& s2, const int& s3){
        if(s1<=s2 && s2<=s3)
            return true;
        else
            return false;
    }
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int sum1(0), sum2(0), sum3(0), total(0), ans(0);
        for(auto& n: nums)
            total += n;
        // cout << total << endl;

        // mid range [i, j]
        int i, j;
        for(i=1; i<n-1; i++)
        {
            sum1 += nums[i-1], sum2 = nums[i], sum3 = total - sum1 - sum2;
            if(chk(sum1, sum2, sum3)) ans++;
            else{
                if(sum1 > sum2);
                else if(sum2 > sum3) continue;
            }
        
            for(j=i+1; j<n-1;j++)
            {
                sum2 += nums[j], sum3 -= nums[j];
                if(chk(sum1, sum2, sum3)) ans++;
                else{
                    if(sum1 > sum2);
                    else if(sum2 > sum3) continue;
                }
            }
        }
        
        return ans;
    }
};

int main()
{

    Solution S;
    return 0;
}