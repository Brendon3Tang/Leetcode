class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {   
            //不要判断nums[k] > target 就返回了，三数之和 可以通过 nums[i] > 0 就返回了，因为 0 已经是确定的数了，四数之和这道题目 target是任意值。
            //比如：数组是[-4, -3, -2, -1]，target是-10，不能因为-4 > -10而跳过。但是我们依旧可以去做剪枝，
            //逻辑变成nums[i] > target && (nums[i] >=0 || target >= 0)就可以了。
            if(nums[i] > target && (target >= 0 || nums[i] >= 0))
                break;
            
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            for(int k = i+1; k < nums.size(); k++)
            {
                //此处也要注意
                if(nums[i]+nums[k] > target && (target >= 0 || nums[i]+nums[k] >= 0))
                    break;
                
                if(k > i+1 && nums[k] == nums[k-1])
                    continue;
                
                int left = k+1;
                int right = nums.size()-1;
                while(left < right)
                {
                    if(nums[i]+nums[k] < target - nums[left] - nums[right])
                    {
                        left++;
                        while(left<right && nums[left] == nums[left-1]) left++;
                    }
                    else if(nums[i]+nums[k] > target - nums[left] - nums[right])
                    {
                        right--;
                        while(left<right && nums[right] == nums[right+1]) right--;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[k],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left] == nums[left-1]) left++;
                        while(left<right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        
        return res;
    }
};