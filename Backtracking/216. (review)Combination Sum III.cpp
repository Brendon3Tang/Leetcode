class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(int n, int k, int startIndex, int count){
        if(count > n) return;
        
        if(path.size() == k)
        {
            if(count == n) res.push_back(path);
            return;
        }
        
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            count += i;
            backtracking(n,k,i+1, count);
            path.pop_back();
            count -= i;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n,k,1,0);
        return res;
    }
};
