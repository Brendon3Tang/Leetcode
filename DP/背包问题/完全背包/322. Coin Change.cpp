class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //it needs at least dp[j] coins to reach amount j.
        vector<int> dp(amount + 1,1000); //初始化一个极大的数，因为要找最小值
        
        if(amount == 0)
            return 0;
     
        dp[0] = 0;
        for(int coin : coins)
        {
            for(int j = coin; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j-coin]+1);//左边的dp[j]可看成dp[i][j]为当考虑当第i个（当前）coin时，至少需要dp[j]个硬币达到j
                //右边：
                //不考虑第i个（当前）coin的情况：的dp[j]可看成dp[i-1][j]，为不考虑第i个（当前）coin时，至少需要dp[j]个硬币达到j。
                //考虑第i个（当前）coin的情况：dp[j-coin]可看成dp[i-1][j-coin]，为不考虑第i个coin时至少需要dp[j-coin]个硬币达到j-coin，而在此基础上要达到j，则加上1个第i个coin即可。
                //取两种情况中的最小值
            }
        }
        
        if(dp[amount] == 1000)
            return -1;
        
        return dp[amount];
    }
};