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
#include "Dijkstra Algorithm using STL.hpp"
using namespace std;

int main()
{
	// create the graph given in above fugure
	int V = 9;
	Dijkstra g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestPath(0);

    return 0;
}