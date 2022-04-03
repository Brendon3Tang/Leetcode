class Solution {
public:
    int uniquePaths(int m, int n) {
        vector memo(m, vector<int>(n,0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0 && i == 0)
                    memo[0][0] = 1;
                else if(j == 0 && i > 0)
                    memo[i][j] = memo[i-1][j];
                else if(i == 0 && j >0)
                    memo[i][j] = memo[i][j-1];
                else
                    memo[i][j] = memo[i][j-1] + memo[i-1][j];
            }
        }
        
        return memo[m-1][n-1];
    }
};