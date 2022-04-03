class Solution {
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
};