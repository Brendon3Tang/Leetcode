class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[j] is the bool if the string s can be segmented into wordDict when it takes the j characters. dp[0] = 0 since it stands for empty str
        vector<bool> dp(s.size()+1,false);
        unordered_set wordSet(wordDict.begin(),wordDict.end());
        
        dp[0] = true;
         
        for(int i = 1; i < s.size()+1; i++)
        {
            for(int j = 0; j < i; j++)
            {
                string substr = s.substr(j, i - j);
                if(wordSet.find(substr) != wordSet.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};