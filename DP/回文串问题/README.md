# 1.回文子串与回文子序列的区别：
    回⽂⼦串(substring)是要连续的，回⽂⼦序列(subsequence)可不是连续的。

# 2.遍历顺序
    - 如果这矩阵是从上到下，从左到右遍历，那么会⽤到没有计算过的dp[i + 1][j - 1]，也就是根据不确定是不是回⽂的区间[i+1,j-1]，来判断了[i,j]是不是回⽂，那结果⼀定是不对的。所以⼀定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
    - j=i表示考虑了当子序列长度为1的情况。（此时要在遍历前将所有的dp[i][i]设置为1）
    - j=i+1则表示从子序列长度为2开始考虑。

# 3.递推公式：
    - 在判断回文子串的题目中，关键逻辑就是看s[i]与s[j]是否相同。
    1. 如果s[i]与s[j]相同，那么当dp[ i ][ j ]表示长度时， dp[ i ][ j ] = dp[i + 1][j - 1] + 2; 那么当dp[ i ][ j ]表示是否是回文串时， dp[ i ][ j ] = dp[i + 1][j - 1];
    2. 如果s[i]与s[j]不相同，那么当dp[ i ][ j ]表示长度时， dp[ i ][ j ] =  max(dp[i + 1][j], dp[i][j - 1]); 那么当dp[ i ][ j ]表示是否是回文串时， 一定是dp[ i ][ j ] = false;