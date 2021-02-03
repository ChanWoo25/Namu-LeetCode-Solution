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

#include "SegmentTree.hpp"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    }
};

int main()
{
    std::vector<int> arr{1, 3, 5, 7, 9, 11};
    SegmentTree<int> ST(arr);
    ST.print();

    cout << ST.Query({1, 3}) << endl;
    cout << ST.Query({0, 4}) << endl;
    int i=2, diff = -2;
    arr[i] += diff;
    ST.Update(i, diff);
    cout << ST.Query({1, 3}) << endl;
    cout << ST.Query({0, 4}) << endl;


    Solution S;
    return 0;
}