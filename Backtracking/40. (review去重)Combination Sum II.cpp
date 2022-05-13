class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startIndex, int count, vector<bool> used)
    {
        if(count > target)
            return;
        else if (count == target)
        {
            res.push_back(path);
            return;
        }
        //本题的难点：去重，candidates里的数只能使用一次：
        //每一树层只能使用一次（即[0，1，0]和[1，0，0]只能出现其中一个），每一树枝可以使用无限次（即[1，1，1]这种有多个1的是允许的）
        //先sort，然后用used判断  
        for(int i = startIndex; i < candidates.size(); i++)
        {
            //candidates[i] == candidates[i-1]说明有重复的数字了，如果used[i-1]==true，说明这是在纵向递归（即树枝）；如果used[i-1]==false，说明是横向递归（即数层），此时由于这个candidate是重复的数字，我们直接跳过这个candidate
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
                continue;
            if(count + candidates[i] <= target)
            {
                path.push_back(candidates[i]);
                count += candidates[i];
                used[i] = true;
                backtracking(candidates, target, i+1, count, used);
                used[i] = false;
                path.pop_back();
                count -= candidates[i];
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0)
            return res;
        
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(),candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return res;
    }
};