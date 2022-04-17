/*class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),0);
        
        if(nums.empty())
            return 0;
        
        memo[0] = nums[0];
        if(nums.size() > 1)
            memo[1] = max(nums[0],nums[1]);
        
        for(int i = 2; i < nums.size(); i++)
            memo[i] = max(memo[i-1], nums[i] + memo[i-2]);
        
        return memo[nums.size()-1];
    }
};*/
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i] stands for that the largest amount is dp[i] when there are i houses.
        //dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        vector<int> dp (nums.size()+1, 0); 
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i = 2; i <= nums.size(); i ++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        
        return dp[nums.size()];
    }
};