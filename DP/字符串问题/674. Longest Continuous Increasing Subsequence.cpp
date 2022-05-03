class Solution {
    //概括来说：不连续递增⼦序列的跟前0-i 个状态有关，连续递增的⼦序列只跟前⼀个状态有关
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0 || nums.size() == 1)
            return nums.size();
        vector<int> dp(nums.size(),1);
        int res = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1]+1;
            
            if(dp[i] > res)
                res = dp[i];
        }
        
        return res;
    }
};