class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> nums, vector<bool>used)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i] == true)
                continue;
            
            used[i] = 1;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i] = 0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0)
            return res;
        vector<bool> used(nums.size(),false);
        backtracking(nums, used);
        return res;
    }
};