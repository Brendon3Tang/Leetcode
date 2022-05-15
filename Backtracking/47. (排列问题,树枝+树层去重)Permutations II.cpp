class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int> nums, vector<bool> levelDup){
        if(nums.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size();i++)
        {
            if((i > 0 && nums[i] == nums[i-1] && levelDup[i-1] == false )|| levelDup[i] == true)
                continue;
            
            
            levelDup[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, levelDup);
            path.pop_back();
            levelDup[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        
        sort(nums.begin(), nums.end());
        vector<bool> levelDup(nums.size(),false);
        backtracking(nums, levelDup);
        return res;
    }
};