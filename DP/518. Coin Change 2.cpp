class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        //dp[j]表示有dp[j]种方法凑齐amount为j的钱
        dp[0] = 1;
        for(int coin : coins)
        {
            for(int j = coin; j <= amount; j++)
                    dp[j] +=  dp[j-coin]; //dp[j] = dp[j] + dp[j-coin]
                    // 考虑当前coin时达到j的方法总数dp[j] = 不考虑当前coin时达到j的方法总数dp[j]+不考虑当前coin时达到j-coin的方法总数dp[j-coin]
                    //例如[1,2,5] amount = 5
                    //当coin=2,amount/j=5时，考虑coin=2时达到5的方法总数dp[5] = 不考虑coin=2时达到5的方法总数dp[5](dp[5] = 1:[1,1,1,1,1])+不考虑coin=2时达到3的方法总数dp[3](dp[3] = 2: [1,1,1],[1,2])，给dp[3]的两种情况加个2就达到amount=5的要求了。
        }
        return dp[amount];
    }
};