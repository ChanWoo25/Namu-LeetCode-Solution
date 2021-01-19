#include "../libs.hpp"


class Solution{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) { 
        vector<int> ret; 
        // Exception Handling. 
        if(matrix.size() == 0) 
            return ret; 
        int m = matrix.size(), n = matrix[0].size(); 
        int i = 0, j = 0; 
        // Goal Constraint 
        while((i+j) < (m+n-1)) 
        { 
            if((i+j)%2 == 0) 
            {   // Right-Up Direction 
                while(i >= 0 && j < n) 
                    ret.push_back(matrix[i--][j++]); 
                i++, j--; 
                
                // Move to Next Diagonal. 
                if(j < n-1) j++; 
                else        i++; 
            } 
            else 
            {   // Left-Down Direction 
                while(i < m && j >= 0) 
                    ret.push_back(matrix[i++][j--]); 
                i--, j++; 
                
                // Move to Next Diagonal. 
                if(i < m-1) i++; 
                else        j++; 
            } 
        } 
        return ret; 
    }

};

int main()
{

    Solution S;
    return 0;
}