#include "../libs.hpp"

/**1. Grid Map이 주어짐.
 * 2. 가는 길에 체력이 +- 될 수 있고,
 * 3. 최소 거리로 도달하기 위해 가져야할 K의 최소 체력을 구하는 문제
 *    => 입을 수 있는 최소한의 피해량을 구하는 문제.
 * 4. 시작은 Top-Left 도착은 Bottom-Right
 * 
 * Try 1 : 일반 DP풀이로 가려고 했으나, 최종적으로 더 낮은 체력으로 가능하더라도,
 *  요점은  Path를 지나는 중 "어떠한 순간도" 체력이 0 미만으로 떨어지면 안된다는 것을 간과하였다. 이는 DP로 해결 불가능
 * 
 * Sol 1 : 풀이를 보니 DP를 잘 이용하면 해결 가능
 * - 처음 생각했던 것처럼 DP는 Bottom-Right에서부터 시작. 최소dp를 구해나가는 것은 각 노드의 Right cell, Bottom cell로부터.
 * - 풀이에 불필요 조건문을 포함시키지 않기 위해, dp는 M+1 * N+1 크기로 할당.
 * - R과 B 중에 더 작은 셀 선택 (= 더 적은 최소 체력이 필요한 셀) - 현재 셀 데미지(또는 오브)
 * - 만약 위 계산이 음수이면, 현재 셀을 기준으로 Right-Bottom까지 가는 길은 체력이 남는다. 
 *      => 필요 최소체력을 1로 초기화하고 현재 셀까지의 최소 체력만 충족되면 됨.
 * - 만약 위 계산이 양수이면, 필요 최소 체력이 갱신된 것임. 계속 진행.
 * 
 * Sol 2 : 위 풀이는 Memory Space O(MN)이 필요함. 하지만 우리가 사용하는 것은 결국 한 열 뿐임.
 * - 생각하기 조금 어렵지만, 아래 Solution2와 같은 방식으로 O(N)으로 공간복잡도를 줄일 수 있음.
 * 
 * Sol 3 : 만약 처음에 생각했던 풀이를 잘 이어나갔으면, Solution3 같은 풀이가 나왔을 것.
*/
class Solution1 {
private:
    vector<vector<int>> dp;
    int m, n;
public:
    int calculateMinimumHP(vector<vector<int>>& DG) {
        if(DG.empty()) 
            return -1;
        m = DG.size(), n = DG[0].size();
        dp.assign(m+1, vector<int>(n+1, INT32_MAX));
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;

        for(int r = m-1; r >= 0; r--)
        {
            for(int c = n-1; c >= 0; c--)
            {
                int minVal = min(dp[r+1][c], dp[r][c+1]) - DG[r][c];
                dp[r][c] = max(1, minVal);
            }
        }
        return dp[0][0];
    }   
};

class Solution2
{
private:
    vector<int> DP;
    int m, n;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) 
            return -1;
        m = dungeon.size(), n = dungeon[0].size();
        DP.assign(n+1, INT32_MAX);
        DP[n-1] = 1;

        for(int r = m-1; r >= 0; r--)
            for(int c = n-1; c >= 0; c--)
                DP[c] = max(1, min(DP[c], DP[c+1]) - dungeon[r][c]);
        
        return DP[0];
    }   
};


class Solution3
{
private:
    vector<int> DP;
    int m, n;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) 
            return -1;
        m = dungeon.size(), n = dungeon[0].size();
        DP.assign(n+1, INT32_MIN);
        DP[n-1] = 0;

        for(int r = m-1; r >= 0; r--)
            for(int c = n-1; c >= 0; c--){
                // Calculate less damage cell.So that we got finally minimum HP needed.
                int maxDamage = max(DP[c], DP[c+1]) + dungeon[r][c];

                // If maxDamage is less than 0, don't need any HP from this cell. 
                // So Initialize to 0 again.
                DP[c] = min(0, maxDamage);
            }
        return (-DP[0] + 1);
    }   
};

int main()
{
    vector<vi> in = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution1 S1;
    cout << S1.calculateMinimumHP(in) << endl;

    return 0;
}