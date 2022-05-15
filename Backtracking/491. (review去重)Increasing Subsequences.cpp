class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int> nums, int startIndex)
    {
        if(path.size() > 1)
            res.push_back(path);
        
        if(startIndex >= nums.size())
            return;
        
        int hashmap[201] = {0}; //nums的范围在-100 ~ 100， 所以用index1-100表示负数，101-200表示正数。有index200所以要建201个array
        for(int i = startIndex; i < nums.size(); i++)
        {
            //情况一：如果path不是空且当前数nums[i] < path.back()，即当前数与path里的子序列无法组成递增子序列，我们需要跳过
            //情况二：如果当前数在本层递归的之前的for loop里已经出现过了，我们要跳过。（在树枝中有重复没关系，所以hashmap在每一层的递归都会重新初始化）
           if( (!path.empty() && nums[i] < path.back()) 
               || hashmap[nums[i] + 100] == 1)
                continue;
            
            //如果path是空的话则要在path里push当前的数，
            //如果path.back <= 当前数nums[i]的话，也要在path里push当前数nums[i]。
            //如果当前数在本层递归的之前的for loop里没出现过，且满足上面条件的话，要在path里push当前的nums[i]
            hashmap[nums[i]+100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        
        backtracking(nums, 0);
        return res;
    }
};