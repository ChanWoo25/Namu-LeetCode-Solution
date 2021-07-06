#include "../libs.hpp"


class Solution{
public: 
    string sol(string S, int K) 
    { 
        long size = 0; 
        unsigned i = 0; 
        int n = S.length(); 
        //Find the size 
        for(i = 0; size < K; i++) 
            size = \ 
            (isdigit(S[i])) ? (size*(S[i]-'0')) : (size+1);  
        
        while(i--) 
        { 
            char c = S[i]; 
            K %= size; 
            if(isdigit(c)) 
                size /= (c-'0'); 
            else // isalpha(c) 
            { 
                if(K == 0)  
                    return string(1, c); 
                else  
                    size--; 
            } 
        }
        return "";
    }
};

int main()
{

    Solution S;
    return 0;
}