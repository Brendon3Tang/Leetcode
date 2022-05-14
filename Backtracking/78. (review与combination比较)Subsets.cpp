class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int> nums, int startIndex)
    {
        res.push_back(path);
        if(startIndex >= nums.size())
            return;
        
        for(int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return res;
    }
};