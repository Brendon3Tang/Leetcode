class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> memo(nums.size(),0);
        
        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                memo[i] = memo[i-1] + 1; 
                // memo[i]的数量 = memo[i-1]的数量 + 1。 
                /*原因：
                    dp[2] = 1
                        [0, 1, 2]
                    dp[3] = dp[2] + 1 = 2
                        [0, 1, 2, 3], // [0, 1, 2] 之后加一个 3
                        [1, 2, 3]     // 新的递增子区间
                    dp[4] = dp[3] + 1 = 3
                        [0, 1, 2, 3, 4], // [0, 1, 2, 3] 之后加一个 4
                        [1, 2, 3, 4],    // [1, 2, 3] 之后加一个 4
                        [2, 3, 4]        // 新的递增子区间
                */
        }
        
        int total = 0;
        for(int item : memo)
            total += item;
        
        return total;//最后返回的是所有的数列，每个memo中都有几个不同的数列，每个memo中的数列的和即为最终结果
    }
};