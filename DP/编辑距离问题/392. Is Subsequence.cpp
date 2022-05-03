class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<bool>> dp(s.length()+1, vector<bool> (t.length()+1,false));
        for(int i = 0; i < t.length()+1; i++)
            dp[0][i] = true;
        for(int i = 1; i < s.length()+1; i++)
        {
            for(int j = i; j < t.length()+1; j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        if(s.empty())
            return true;
        return dp[s.length()][t.length()];
    }
};