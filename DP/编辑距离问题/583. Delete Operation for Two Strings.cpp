class Solution {
    /*
    确定递推公式:
        1.当word1[i - 1] 与 word2[j - 1]相同的时候，dp[i][j] = dp[i - 1][j - 1];
        2.当word1[i - 1] 与 word2[j - 1]不相同的时候，有三种情况：
            情况⼀：删word1[i - 1]，最少操作次数为dp[i - 1][j]（之前求过） + 1 (+1个删除步骤)
            情况⼆：删word2[j - 1]，最少操作次数为dp[i][j - 1] + 1
            情况三：同时删word1[i - 1]和word2[j - 1]，操作的最少次数为dp[i - 1][j - 1] + 2
            那最后当然是取最⼩值，所以当word1[i - 1] 与 word2[j - 1]不相同的时候，递推公式：dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
    */
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,0));
        dp[0][0] = 0;
        for(int i = 1; i < word1.size()+1; i++)
            dp[i][0] = i;
        for(int i = 1; i < word2.size()+1; i++)
            dp[0][i] = i;
        
        for(int i = 1; i < word1.size()+1; i++)
        {
            for(int j = 1; j < word2.size()+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min({dp[i-1][j-1]+2,dp[i][j-1]+1, dp[i-1][j]+1});
            }
        }
        return dp[word1.size()][word2.size()];
    }
};