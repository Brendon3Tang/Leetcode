class Solution {
private:
    vector<string> res;
    const string lettermap[10] = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    
    void backtracking(string digits, int startIndex, string str)
    {
        if(str.size() == digits.size())
        {
            res.push_back(str);
            return;
        }
        
        int idx = digits[startIndex] - '0';
        
        for(int i = 0; i < lettermap[idx].size(); i++)
        {
            str.push_back(lettermap[idx][i]);
            backtracking(digits, startIndex+1, str);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;
        
        string str = "";
        backtracking(digits, 0, str);
        
        return res;
    }
};