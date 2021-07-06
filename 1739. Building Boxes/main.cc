#include "../libs.hpp"


class Solution {
private:
    int getLayerSize(int x){
        return x * (x+1) / 2;
    }
    int getCubeSize(int x){
        long d = static_cast<long>(x);
        long sz = (d * (d+1) * (d+2)) / 6;
        return static_cast<int>(sz);
    }
public:

    int minimumBoxes(int n) {
        // First Binary Search
        int l(0), r(2000), m;
        while(l <= r)
        {
            m = (l+r)/2;
            int sz = getCubeSize(m);
            if(sz <= n)
                l = m + 1;
            else
                r = m - 1;
        }
        int aSideOfPyramid = r;
        int rest = n - getCubeSize(aSideOfPyramid);
        
        l=0,r=2000;
        while(l <= r)
        {
            m = (l+r)/2;
            int sz = getLayerSize(m);
            if(sz < rest)
                l = m + 1;
            else
                r = m - 1;
        }
        int addedFloorCubic = l;

        return getLayerSize(aSideOfPyramid) + addedFloorCubic;
    }
};

int main()
{

    Solution S;
    cout << S.minimumBoxes(51) << endl;

    return 0;
}