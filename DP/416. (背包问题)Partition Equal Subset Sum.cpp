/*class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        if(sum % 2 != 0)
            return false;
        
        int target = sum/2;
        
        vector<vector<bool>> memo(nums.size(), vector<bool>(target + 1,false));
        
        if(nums[0] <= target)
            memo[0][nums[0]] = true;
        
        for(int i = 1; i < nums.size();i++)
        {
            for(int j = 0; j <= target; j++)
            {
                 memo[i][j] = memo[i-1][j];  //不拿。
            
                //拿，且背包容积与物品体积刚好相等
                if(nums[i] == j){
                    memo[i][j] = true;
                    continue;
                }
                
                //拿，且背包容积大于物品体积
                if(nums[i] < j)
                    memo[i][j] = memo[i-1][j] || memo[i-1][j-nums[i]];//比较拿与不拿，选择最优的那个
            }
        }
        
        return memo[nums.size()-1][target];
    }
};*/
//空间优化到一维数组后
//dp[j]为当背包容量为j时，最大可以凑成j的子集总和dp[j]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        if(sum % 2 != 0)   
            return false;
        
        vector<int> dp((sum/2) + 1,0);
        int target = sum/2;
        dp[0] = 0; //
        for(int i = 0; i < nums.size(); i++) 
        {
            for(int j = target; j >= nums[i]; j--) { // 每⼀个元素⼀定是不可重复放⼊，所以从⼤到⼩遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
                return false;
    }
};