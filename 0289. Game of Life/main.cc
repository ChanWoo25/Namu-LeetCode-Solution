#include "../libs.hpp"


class Solution { 
public: 
    int m, n; 
    int count1s(vector<vector<int>>& board, int i, int j) 
    { 
        int ret = 0; 
        // max와 min을 활용하여 불필요한 range 검사를 줄인다.
        for(int r=max(i-1, 0); r<min(i+2, m); r++) 
            for(int c=max(j-1, 0); c<min(j+2, n); c++) 
                if((r!=i || c!=j) && (board[r][c]&1)) 
                    ret++; 
        return ret; 
    } 
    void gameOfLife(vector<vector<int>>& board) { 
        m = board.size(), n = board[0].size(); 
        for(int r=0; r<m; r++) 
            for(int c=0; c<n; c++) 
            {   // first bit for currnt, second bit for next state. 
                int cnt = count1s(board, r, c); 
                int &curr = board[r][c]; 
                if((curr&1) && cnt > 1 && cnt < 4) 
                    curr |= 2; 
                else if(!(curr&1) && cnt == 3) 
                    curr |= 2; 
            } 
        // 2번째 비트를 사용함으로써 두번째 반복문에서 단 하나의 Bit shift만으로 다음 state를 얻을 수 있다.
        for(int r=0; r<m; r++) 
            for(int c=0; c<n; c++) 
                board[r][c] >>= 1; 
    } 
};

int main()
{

    Solution S;
    return 0;
}