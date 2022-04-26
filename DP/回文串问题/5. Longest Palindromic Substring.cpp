class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i][j]表示字符串中从i到j为止的字符都是回文
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),0));
        string res;
        res += s[0];
        //遍历逻辑：abba中，如果s[1][2]为回文，且s[0]=s[3]，则s[0][3]一定也是回文。 即要先比较s[1],s[2]，如果dp[1][2]为true，且s[0] = s[3]，则dp[0][3]为true
        //注意遍历顺序，两层遍历顺序要反着来，否则会出现“在dp[1][2]得出结果之前就会根据dp[1][2]来求dp[1][3]”的情况
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {   //j-i+1 = 当前字符串的长度。 如果当前字符串长为1，一定是回文，如果为2，由于s[i]==s[j]，也一定是回文 
                    if(j-i+1 <= 2 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                    
                        if(j-i+1 > res.length())
                            res = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res;
    }
};