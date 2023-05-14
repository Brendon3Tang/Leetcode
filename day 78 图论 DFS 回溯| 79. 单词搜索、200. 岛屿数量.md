# [79. 单词搜索](https://leetcode.cn/problems/word-search/)
### 题目：
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例 1：
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```
示例 2：
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
```
示例 3：
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
```

提示：
```
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board 和 word 仅由大小写英文字母组成
```
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 回溯，上下左右寻找。
- 核心剪枝：if(word[strSize] != board[i][j])    return false;   //对于不相等的值，完全没必要进行递归


### 难点：
- 核心剪枝：对于不相等的值，完全没必要进行递归

### 代码：  
```
class Solution {
public:
    bool backtracking(const vector<vector<char>>& board, vector<vector<bool>> &checked, int i, int j, int strSize, const string &word){
        if(strSize == word.size())    return true;
        if(strSize > word.size())   return false;  //剪枝
        int M = board.size(), N = board[0].size();

        if(i < 0 || i >= M) return false;
        if(j < 0 || j >= N) return false;
        if(word[strSize] != board[i][j])    return false;   //核心剪枝：对于不相等的值，完全没必要进行递归
        if(checked[i][j])   return false;

        checked[i][j] = true;
        if(backtracking(board, checked, i, j+1, strSize+1, word))    return true;
        if(backtracking(board, checked, i, j-1, strSize+1, word))    return true;
        if(backtracking(board, checked, i+1, j, strSize+1, word))    return true;
        if(backtracking(board, checked, i-1, j, strSize+1, word))    return true;
        checked[i][j] = false;
            
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> checked(m, vector<bool>(n,false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backtracking(board, checked, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
```


# [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands/)
### 题目：
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：
```
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
```
示例 2：
```
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
```

提示：
```
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- DFS，可用递归实现，也可用栈实现，用visited数组储存遍历过的节点
- 遍历grid数组：
  - 当节点是0或者已经visited时，跳过
  - 否则把当前节点放入stack中，然后从当前节点开始深度搜索
    - 深度搜索要搜索上下左右四个方向，如果是1且未visited，则放入栈中
    - 当栈为空时，表示从起始节点开始的node set遍历完了，他就是一个岛，count++
  - 继续遍历grid数组，直到结束。


### 难点：
- dfs需要遍历四个方向

### 代码（栈实现）：  
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        if(row == 1 && col == 1)    return grid[0][0]-'0';

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        stack<pair<int,int>> st;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(visited[i][j] == true || grid[i][j] == '0')   continue;
                st.emplace(i,j);
                while(!st.empty()){
                    int curR = st.top().first;
                    int curC = st.top().second;
                    visited[curR][curC] = true;
                    st.pop();
                    if(curR-1 >= 0 && grid[curR-1][curC] == '1' && visited[curR-1][curC] != true)   st.emplace(curR-1, curC);
                    if(curR+1 < row && grid[curR+1][curC] == '1' && visited[curR+1][curC] != true)   st.emplace(curR+1, curC);
                    if(curC+1 < col && grid[curR][curC+1] == '1' && visited[curR][curC+1] != true)   st.emplace(curR, curC+1);
                    if(curC-1 >= 0 && grid[curR][curC-1] == '1' && visited[curR][curC-1] != true)   st.emplace(curR, curC-1);
                }
                count++;
            }
        }
        
        return count;
    }
};
```