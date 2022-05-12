class Solution {
private: 
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startIndex, int count)
    {
        if(count > target)
            return;
        else if(count == target)
        {
            res.push_back(path);
            return;
        }
        
        for(int i = startIndex; i < candidates.size(); i++)
        {
            if(count + candidates[i] <= target)
            {
                path.push_back(candidates[i]);
                count = count + candidates[i];
                backtracking(candidates,target, i, count);
                count = count - candidates[i];
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0)
            return res;
        backtracking(candidates, target, 0, 0);
        return res;
    }
};