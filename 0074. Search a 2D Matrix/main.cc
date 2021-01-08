#include "../libs.hpp"


class Solution {
public:
    // Binary Search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int low = 0, high = m*n - 1, i;
        while(low <= high)
        {
            i = (low+high)/2; 
            if(matrix[i/n][i%n] < target)
                low = i + 1;
            else if(target < matrix[i/n][i%n])
                high = i - 1;
            else 
                return true;
        }
        return false;
    }

    // Greedy Search
    bool searchMatrix2(vector<vector<int>>& matrix, int target) 
    {
        int row(0), col(matrix[0].size());
        while(row < matrix.size() and col >= 0)
        {
            if(target == matrix[row][col])
                return true;
            if(matrix[row][col] < target) 
                row++;
            else
                col--;
        }
        return false;
    }  
};

int main()
{

    Solution S;
    return 0;
}