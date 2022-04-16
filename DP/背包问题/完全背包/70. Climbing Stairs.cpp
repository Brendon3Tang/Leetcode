/*class Solution {
public:
    int climbStairs(int n) {
        //1.base case
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        int pre1, pre2;
        pre1 = 1;
        pre2 = 2;
        int sum = 0;
        for(int i = 3; i <= n; i++)
        {
            sum = pre1 + pre2;
            pre1 = pre2;
            pre2 = sum;
        }
        return sum;
    }
};*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 1; j <= 2; j++)
            {
                if(i >= j)
                    dp[i] += dp[i-j];
            }
        }
        return dp[n];
    }
};