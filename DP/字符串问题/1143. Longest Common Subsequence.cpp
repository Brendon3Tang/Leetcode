class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.length()+1][text2.length()+1];
        
        for(int i = 0; i <= text1.length(); i++)
        {
            for(int j = 0; j <= text2.length(); j++)
                dp[i][j] = 0;    
        }
        
        for(int m = 1; m <= text1.length(); m++)
        {
            for(int n = 1; n <= text2.length(); n++)
            {
                if(text2[n-1] == text1[m-1])
                    dp[m][n] = dp[m-1][n-1] + 1;
                else
                    dp[m][n] = max(dp[m][n-1],dp[m-1][n]);
            }  
        }
        
        return dp[text1.length()][text2.length()];
    }
};