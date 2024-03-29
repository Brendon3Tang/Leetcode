class Solution {
public:
    int numDistinct(string s, string t) {
        /*
        s[i-1] = t[j-1]:
        1.dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        
        s[i-1] != t[j-1]:
        dp[i][j] = dp[i-1][j]
        当s[i - 1] 与 t[j - 1]相等时，dp[i][j]可以有两部分组成。
            ⼀部分是⽤s[i - 1]来匹配，那么个数为dp[i - 1][j - 1]。
            ⼀部分是不⽤s[i - 1]来匹配，个数为dp[i - 1][j]。
        这⾥可能有同学不明⽩了，为什么还要考虑 不⽤s[i - 1]来匹配，都相同了指定要匹配啊。
        例如： s：bagg 和 t：bag ，s[3] 和 t[2]是相同的，但是字符串s也可以不⽤s[3]来匹配，即⽤s[0]s[1]s[2]组成的bag。
        当然也可以⽤s[3]来匹配，即：s[0]s[1]s[3]组成的bag。所以当s[i - 1] 与 t[j - 1]相等时，dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        当s[i - 1] 与 t[j - 1]不相等时，dp[i][j]只有⼀部分组成，不⽤s[i - 1]来匹配，即：dp[i - 1][j]
        所以递推公式为：dp[i][j] = dp[i - 1][j]
        */
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1,0));
        for(int i = 0; i < s.size()+1; i++)//当t为空集时，由于所有s的子集都有一个子集为空集，所以所有s都有一个子集等于t，所以dp[i][0]=1
            dp[i][0] = 1;
        
        for(int i = 1; i < s.size()+1; i++)
        {
            for(int j = 1; j < t.size()+1;j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};