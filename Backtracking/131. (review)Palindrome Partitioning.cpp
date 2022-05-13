class Solution {
    vector<vector<string>> res;
    vector<string> path;
    
    bool isPalindrome(string s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    
    void backtracking(string s, int startIndex){
        if(startIndex >= s.size())
        {
            if(!path.empty())
                res.push_back(path);
            return;
        }
        
        for(int i = startIndex; i < s.size(); i++)
        {
            if(isPalindrome(s,startIndex,i) == true)
                path.push_back(s.substr(startIndex,i-startIndex+1));
            else//不是回文要跳过
                continue;
            backtracking(s,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.size()==0)
            return res;
        
        backtracking(s,0);
        return res;
    }
};