class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int res = INT32_MAX;
        
        for(int right = 0; right < nums.size(); right++)
        {
            sum = sum+nums[right];
            while(sum >= target)
            {
                sum = sum - nums[left];
                if(right - left + 1 < res)
                    res = right - left + 1;
                left++;
            }
        }
        if(res == INT32_MAX)
            return 0;
        return res;
    }
};