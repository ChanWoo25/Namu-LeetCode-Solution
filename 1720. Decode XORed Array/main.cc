#include "../libs.hpp"

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        int bitsize = 1e5;
        vi arr(n + 1, 0);
        arr[0] = first;
        for(uint i=1; i<=n; i++)
        {
            int mask = encoded[i-1];
            // arr[i] = (arr[i-1] & (~mask)) + ((~arr[i-1]) & mask);
            arr[i] = arr[i-1] ^ encoded[i-1];
        }
        return arr;
    }
};
int main()
{
    vi v = {6,2,7,3};
    int f = 4;
    Solution S;
    vi a = S.decode(v, f);
    for(auto x: a)
        cout << x << ' ';
    cout << endl;
    return 0;
}