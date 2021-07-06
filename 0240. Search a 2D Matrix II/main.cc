#include "../libs.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();

        int row(0), col(n-1);
        while(row < m && 0 <= col)
        {
            int e = matrix[row][col];
            if(e < target)
                row++;
            else if(e > target)
                col--;
            else // if(e == target)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<vi> input{
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,13,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int t = 5;
    Solution S;
    cout << S.searchMatrix(input, t);

    return 0;
}