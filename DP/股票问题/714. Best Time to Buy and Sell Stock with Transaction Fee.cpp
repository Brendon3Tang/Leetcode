class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0]; //在第i=0天为买入股票状态时的余额
        dp[0][1] = 0; //在第i=0天为售出股票状态时的余额
        
        for(int i = 1; i < prices.size();i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i][0]+prices[i]-fee);
        }
        
        return dp[prices.size()-1][1];
    }
};