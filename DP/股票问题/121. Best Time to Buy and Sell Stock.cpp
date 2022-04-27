// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int low = INT_MAX;
//         int res = 0;
//         for(int i = 0; i < prices.size();i++)
//         {
//             low = min(low, prices[i]);
//             res = max(res, prices[i]-low);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        //dp[i][0]表示第i天由于持有股票而花费的钱：(分两种情况)
            //1.在第i天之前就已经持有股票，因此花费的钱是第i天之前时股票的价格，即dp[i][0] = dp[i-1][0]
            //2.在第i天才持有的股票，因此花费的钱就是第i天时股票的价格，即dp[i][0] = prices[i]
            //我们要在到第i天为止的最便宜的一天买入股票，因此dp[i][0] = min(dp[i-1][0],prices[i])
        //do[i][1]表示第i天由于售出股票而得到的钱：
            //1.在第i天之前就已经卖掉了股票，因此得到的钱是第i天之前时卖股票的利润，即dp[i][1] = dp[i-1][1]
            //2.在第i天才卖掉的的股票，因此得到的钱就是第i天时卖股票的利润，即dp[i][1] = prices[i] - dp[i][0]
            //我们要在到第i天为止的最贵的一天售出股票，因此dp[i][1] = min(dp[i-1][1],prices[i]-dp[i][0])
        dp[0][0] = prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = min(dp[i-1][0],prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] - dp[i][0]);
        }
        if(prices.size() == 0)
            return 0;
        return dp[prices.size()-1][1];
    }
};