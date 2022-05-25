class Solution {
private:
    bool isValid(int row, int col, char val, vector<vector<char>> board){
        for(int i = 0; i < board.size(); i++)//check column
        {
            if(val == board[i][col])
                return false;
        }
        for(int j = 0; j < board[0].size();j++)//check row
        {
            if(val == board[row][j])
                return false;
        }
        
        int startRow = (row/3)*3;  //(0至2)/3 = 0， (3至5)/3 = 1
        int startCol = (col/3)*3;
        for(int i = startRow; i < startRow+3; i++)//check sub-boxes
        {
            for(int j =startCol; j < startCol+3; j++)
            {
                if(val == board[i][j])
                    return false;
            }
        }
        
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++)//遍历行
        {
            for(int j = 0; j < board[0].size();j++)//遍历列
            {
                if(board[i][j] != '.') continue;//如果当前spot有字符，则跳到下一个spot
                for(int k = '1'; k <= '9'; k++)//如果没字符，则从1到9开始放字符逐个尝试
                {
                    if(isValid(i,j,k,board))//如果当前字符valid
                    {
                        board[i][j] = k;//尝试放当前字符k
                        if(backtracking(board)) return true;//把放了当前数字的board进行新一轮backtracking，如果可行则return true
                        board[i][j] = '.';//如果不可行则撤销k
                    }
                }
                return false;//如果1-9都不能发，说明此时无解了，return
            }
        }
        return true; //如果全都进行完后没问题，return true；
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};