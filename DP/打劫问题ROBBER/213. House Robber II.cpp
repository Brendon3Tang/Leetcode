class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i] stands for that the largest amount is dp[i] when there are i houses.
        //dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        int result1 = 0;
        int result2 = 0;
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() < 3)
            return max(nums[0],nums[1]);
        
        vector<int> dp (nums.size()+1, 0); 
        dp[0] = 0;
        dp[1] = nums[0];
        //假设此时有数组[2,1,1,2]
        //情况一：只考虑子数组[2,1,1]
        for(int i = 2; i <= nums.size()-1; i ++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            result1 = dp[i];
        }
        
        //情况二：只考虑子数组[1,1,2] （通过把dp[1]变成0来代替dp[0]）
        dp[1] = 0;
        for(int i = 2; i <= nums.size(); i ++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            result2 = dp[i];
        }
        
        return max(result1, result2);
    }
};