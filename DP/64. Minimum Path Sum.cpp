class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                //1.base cases
                if(i == 0 && j == 0)
                    memo[i][j] = grid[i][j];
                else if(j == 0 && i > 0)
                    memo[i][0] = memo[i-1][0] + grid[i][j];
                else if(i == 0 && j > 0)
                    memo[0][j] = memo[0][j-1] + grid[i][j];
                //2.state functions
                else
                    memo[i][j] = min(memo[i][j-1], memo[i-1][j]) + grid[i][j];
            }
        }
        return memo[grid.size()-1][grid[0].size()-1];
    }
};