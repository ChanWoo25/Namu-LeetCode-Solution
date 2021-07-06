#include "../libs.hpp"


class Solution {
public:
    int minimumHammingDistance
    (vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) 
    {

        int n = source.size();
        int ans = n;

        vector<int> idxs(n, 0);
        unsigned empty_idx = 1;
        vector<vector<int>> keys; 
        keys.emplace_back(vector<int>(0));
        for(auto it = allowedSwaps.begin(); 
            it != allowedSwaps.end(); it++)
        {
            int a = it->front(), b = it->back(); 
            if(idxs[a] == 0 && idxs[b] == 0)
            {
                idxs[a] = (idxs[b] = empty_idx);
                keys.emplace_back(vector<int>());
                keys[empty_idx].push_back(a);
                keys[empty_idx].push_back(b);
                empty_idx++;
            }
            else if(idxs[a] != 0 && idxs[b] == 0){
                idxs[b] = idxs[a];
                keys[idxs[a]].push_back(b);
            }
            else if(idxs[b] != 0 && idxs[a] == 0){
                idxs[a] = idxs[b];
                keys[idxs[b]].push_back(a);
            }
            else{
                if(idxs[a] != idxs[b]){
                    int ki = idxs[b];
                    for(int i=0; i<keys[ki].size(); i++){
                        int mi = keys[ki][i];
                        keys[idxs[a]].push_back(mi);
                        idxs[mi] = idxs[a];
                    }
                    keys[ki].clear();
                }
                else continue;
            }
        }

        vector<bool> chk(n, false);
        for(int i=0; i<n; i++)
        {
            vector<int> v = keys[idxs[i]];
            if(v.empty())
            {
                chk[i] = true;
                if(source[i] == target[i])
                    ans--;
            }
            else
            {
                for(int& j: v)
                {
                    if(chk[j]) continue;

                    if(source[j] == target[i]){
                        chk[j] = true;
                        ans--;
                    }
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