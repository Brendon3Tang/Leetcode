class Solution {
public:
    int numSquares(int n) {
        //dp[j] stands for there are at least dp[j] number of perfect square numbers that sum to j
        vector<int> dp(n+1, 99999);
        dp[0] = 0;
        //dp[j] = min(dp[j],dp[j-nums[i]]+1)
        int end = sqrt(n);
        for(int i = 1; i <= end; i++)
        {
            for(int j = i*i; j <= n; j++)
                dp[j] = min(dp[j], dp[j-i*i] + 1);
        }
        return dp[n];
    }
};