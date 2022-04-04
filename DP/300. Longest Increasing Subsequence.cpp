class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(),1);
        
        if(nums.empty())
            return 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    memo[i] = max(memo[i], memo[j]+1);    
            }
        }
        
        int tMax = 0;
        for(int item : memo)
            tMax = max(tMax, item);
        
        return tMax;
    }
};