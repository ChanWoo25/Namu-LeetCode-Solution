class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        auto it = arr.begin();
        vector<bool> chk(pieces.size(), false);
        
        while(it != arr.end())
        {   
            int i, j;
            for(i=0; i<pieces.size(); i++)
                if(!chk[i] && (*it) == pieces[i].front())
                    break;
            if(i == pieces.size()) 
                return false;
            
            for(j=0; j<pieces[i].size(); j++)
                if(*it == pieces[i][j]) 
                    it++;
            if(j != pieces[i].size())
                return false;
            
            chk[i] = true;
        }
        
        for(const auto &b: chk)
            if(!b) return false;
        return true;
    }
};
