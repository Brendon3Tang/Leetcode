class Solution {
public:
//位置i的最⻓升序⼦序列等于j从0到i-1各个位置的最⻓升序⼦序列 + 1 的最⼤值。
//所以：if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(),1);
        
        if(nums.empty())
            return 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    memo[i] = max(memo[i], memo[j]+1);   //注意这⾥不是要memo[i] 与 memo[j] + 1进⾏⽐较，⽽是我们要取memo[j] + 1的最⼤值 
            }
        }
        
        int tMax = 0;
        for(int item : memo)
            tMax = max(tMax, item);
        
        return tMax;
    }
};