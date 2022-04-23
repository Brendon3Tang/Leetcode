/*class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //backpack varies from 0 to target (target+1 spots)
        //dp[j] stands for that there are dp[j] ways to assign symbols to make the sum of nums be target j
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        //P: the items that will be put +
        //N: the items that will be put -
        //P+N = sum;
        //P-N = target;
        //so P = target + N = target + (sum - P)
        //so P = (target+sum)/2
        //so the P is the capacity of the backpack since once we get the dp[j] = P, we are done. (If could also be N if we think in other way, then if dp[j] = N, we are done)
        int capacity = (target + sum)/2;
        
        if(capacity < 0)
            return 0;
        
        vector<int> dp(capacity + 1,0);
        if((target + sum) %2 != 0)
            return 0;
        if(target > sum)
            return 0;
        
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = capacity; j >= nums[i]; j--)
            {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[capacity];
    }
};*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //backpack varies from 0 to target (target+1 spots)
        //dp[j] stands for that there are dp[j] ways to assign symbols to make the sum of nums be target j
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        //P: the items that will be put +
        //N: the items that will be put -
        //P+N = sum;
        //P-N = target;
        //so P = target + N = target + (sum - P)
        //so P = (target+sum)/2
        //so the P is the capacity of the backpack since once we get the dp[j] = P, we are done. (If could also be N if we think in other way, then if dp[j] = N, we are done)
        int capacity = (target + sum)/2;
        
        if(capacity < 0)
            return 0;
        
        if((target + sum) % 2 != 0)
            return 0;
        
        if(target > sum)
            return 0;
        
        //新建一个nums.size()+1 X capacity+1的矩阵，其中第一行留空，当中item = -1的情况
        vector<vector<int>> dp(nums.size() + 1, vector<int>(capacity + 1,0));
        
        //当背包容量为0时，只有一种方式填满背包，存入0个
        for(int jt = 0; jt <= nums.size(); jt++)
        {
            dp[jt][0] = 1;
        }
        
        //从item 1开始。i=0时，为item=-1的情况，即不存在，i=0的这一行值全部为0
        for(int i = 1; i <= nums.size(); i++)
        {
            for(int j = 0; j <= capacity; j++)
            {
                if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1])
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
            }
        }
        
        return dp[nums.size()][capacity];
    }
};
