/*
1. 确定dp数组（dp table）以及下标的含义
dp[i][j]：最多有i个0和j个1的strs的最⼤⼦集的⼤⼩为dp[i][j]。
2. 确定递推公式
dp[i][j] 可以由前⼀个strs⾥的字符串推导出来，strs⾥的字符串有zeroNum个0，oneNum个1。
dp[i][j] 就可以是 dp[i - zeroNum][j - oneNum] + 1。
然后我们在遍历的过程中，取dp[i][j]的最⼤值。
所以递推公式：dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
此时⼤家可以回想⼀下01背包的递推公式：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
对⽐⼀下就会发现，字符串的zeroNum和oneNum相当于物品的重量（weight[i]），字符串本身的个数
相当于物品的价值（value[i]）。
这就是⼀个典型的01背包！ 只不过物品的重量有了两个维度⽽已。
3. dp数组如何初始化
因为物品价值不会是负数，初始为0，保证递推的时候dp[i][j]不会被初始值覆盖。
4. 确定遍历顺序
01背包是外层for循环遍历物品，内层for循环遍历背包容量且从后向前遍历！
那么本题也是，物品就是strs⾥的字符串，背包容量就是题⽬描述中的m和n。
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(string str : strs)
        {
            int oneN = 0;
            int zeroN = 0;
            for(char c : str)
            {
                if(c == '0')
                    zeroN++;
                else
                    oneN++;
            }
            
            for(int i = m; i >= zeroN; i--)
            {
                for(int j = n; j >= oneN; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i-zeroN][j-oneN]+1);
                }
            }
        }
        return dp[m][n];
    }
};