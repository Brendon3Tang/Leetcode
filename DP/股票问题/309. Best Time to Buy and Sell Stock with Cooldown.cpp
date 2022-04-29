class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(5,0));
        dp[0][0] = -prices[0]; //保持买入
        dp[0][1] = -prices[0]; //今天买入
        dp[0][2] = 0; //保持卖出
        dp[0][3] = 0; //今天卖出
        dp[0][4] = 0; //冷冻
        
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = max(dp[i-1][4] - prices[i], dp[i-1][2] - prices[i]);
            dp[i][2] = max(dp[i-1][4], dp[i-1][2]);
            dp[i][3] = max(dp[i-1][1] + prices[i], dp[i-1][0]+prices[i]);
            dp[i][4] = dp[i-1][3];
        }
        
        int res = max(dp[prices.size()-1][2],max(dp[prices.size()-1][3],dp[prices.size()-1][4]));
        return res;
    }
};