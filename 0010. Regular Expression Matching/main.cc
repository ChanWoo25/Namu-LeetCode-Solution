#include "../libs.hpp"


class Solution { 
 public: 
  bool isMatch(const string &s, const string &p) { 
    int m = s.size(), n = p.size(); 
    // dp[i][j] represents if the first i characters in s can match the first j characters in p 
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0)); 
     
    // boundary initialization 
    // 1. empty string matches empty pattern 
    dp[0][0] = 1; 
    // 2. dp[i][0] = 0, empty pattern cannot match non-empty string 
    // 3. dp[0][j], what pattern matches empty string ""?  
    // it should be string like '.* a* .*' 
    // the length of pattern should be even && the character at the even position should be * 
    // for odd length, dp[0][j] = false which is default. So we can just skip the odd position, i.e. j starts from 2, the interval of j is also 2.  
    for (int j = 2; j <= n; j += 2) { 
      if (p[j - 1] == '*' && dp[0][j - 2]) { 
        dp[0][j] = 1; 
      } 
    } 
    // Induction rule is very similar to edit distance, 
    // where we also consider from the end. And it is based on what character in the pattern we meet. 
    //    
    // 1. if p.charAt(j) == s.charAt(i), dp[i][j] = dp[i - 1][j - 1] 
    // 2. if p.charAt(j) == '.', dp[i][j] = dp[i - 1][j - 1] 
    // 3. if p.charAt(j) == '*': 
    //    3.1 if p.charAt(j - 1) != '.' && p.charAt(j - 1) != s.charAt(i), 
    //        then b* is counted as empty. dp[i][j] = dp[i][j - 2] 
    //
    //    3.2 if p.charAt(j - 1) == '.' || p.charAt(j - 1) == s.charAt(i): (!(3.1) = (3.2)) 
    //       3.2.1 if p.charAt(j - 1) is counted as empty, then M[i][j] = M[i][j - 2] 
    //       3.2.2 if counted as one, then M[i][j] = M[i - 1][j - 2] 
    //       3.2.3 if counted as multiple, then M[i][j] = M[i - 1][j] 
     
    for (int i = 1; i <= m; ++i) { 
        for (int j = 1; j <= n; ++j) { 
            char curr_s = s[i - 1]; 
            char curr_p = p[j - 1]; 
            // lowercase letter, current match 
            if (curr_s == curr_p) { 
                dp[i][j] = dp[i - 1][j - 1]; 
            } else if (curr_p == '.') { 
                // '.', current match 
                dp[i][j] = dp[i - 1][j - 1]; 
            } else if (p[j - 1] == '*'){ 
                // '*' 
                char prev_p = p[j - 2]; 
                if (prev_p != '.' && curr_s != prev_p) { 
                    // previous character not match, b* count as empty 
                    dp[i][j] = dp[i][j - 2]; 
                } else if (prev_p == '.' || curr_s == prev_p) { 
                    // 새로운 curr_s가 만족하기 때문에 s[i-1]의 정보를 가져올 수 있다.
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];  
                } 
            } 
        } 
    } 
     
    return dp[m][n]; 
  } 
};
int main()
{

    Solution S;
    return 0;
}