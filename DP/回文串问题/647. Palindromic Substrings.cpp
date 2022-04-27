class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),0));
        int res = 0;
        
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i+1 <= 2 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;  
    }
};