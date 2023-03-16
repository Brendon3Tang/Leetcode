# 刷题总结：
#### 本次刷题最大的收获是对**动态规划**题目有了系统性的归纳总结，加强了理解：

# 一、背包问题总结

## 在讲解背包问题的时候，都是按照如下五部来逐步分析:
1. 确定是01背包问题（背包要倒序遍历）还是完全背包问题（背包要正序遍历）；确定是组合问题（外层遍历物品，内层遍历背包）还是排列问题（外层遍历背包，内层遍历物品）还是无所谓
2. 确定dp数组（dp table）以及下标的含义
3. 确定递推公式
4. dp数组如何初始化
5. 确定遍历顺序
6. 举例推导dp数组  
   
其实这五部⾥哪⼀步都很关键，但确定递推公式和确定遍历顺序都具有规律性和代表性，所以下⾯我从这两点来对背包问题做⼀做总结。

## 二维数组为什么可以变成一维滚动数组？
- [复习代码随想录第四十二天笔记，看三道题的思路部分](./../代码随想录算法训练营第四十二天%20|%201049.%20最后一块石头的重量%20II、494.%20目标和、474.%20一和零.md)

## 为什么完全背包可以正序遍历？
- [复习代码随想录第四十五天笔记，看第一道题的思路部分](./../代码随想录算法训练营第四十五天%20|%2070.%20爬楼梯(进阶)、322.%20零钱兑换、279.%20完全平方数.md)
- [ 宫水三叶的刷题日记 -【动态规划/背包问题】从数学角度推导「完全背包」与「01 背包」之间的遍历顺序关系](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247486107&idx=1&sn=e5fa523008fc5588737b7ed801caf4c3&chksm=fd9ca184caeb28926959c0987208a3932ed9c965267ed366b5b82a6fc16d42f1ff40c29db5f1&token=990510480&lang=zh_CN&scene=21#wechat_redirect)（推荐关注公众号后在手机上用日间模式观看，夜间模式/网页版看不清一些公式）

## 为什么排列问题需要背包在外层for loop，物品在里层for loop？
- [139. 单词拆分：拓展部分](https://programmercarl.com/0139.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86.html)

## 背包递推公式
### 问能否能装满背包（或者最多装多少）：
**dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);** ，对应题⽬如下：
- [动态规划：416.分割等和⼦集](https://leetcode.cn/problems/partition-equal-subset-sum/)
- [动态规划：1049.最后⼀块⽯头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii/)

### 问装满背包有⼏种⽅法：
**dp[j] += dp[j - nums[i]]** ，对应题⽬如下：
- [动态规划：494.⽬标和](https://leetcode.cn/problems/target-sum/)
- [动态规划：518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii/)
- [动态规划：377.组合总和Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)
- [动态规划：70. 爬楼梯进阶版（完全背包）](https://leetcode.cn/problems/climbing-stairs/)

### 背包方案数的公式是怎么来的？
- 假设dp[ j ]表示取得价值为j的方案一共有dp[ j ]种。
- 为了方便理解，**可以把背包方案数问题想像成爬楼梯方案数问题**，只是可选择的步数不只有{1,2}两种，而是有{coins[ 0 ], coins[ 1 ], ..., coins[ n ]} n种。所以上到第 j 阶楼梯的方法有dp[j - coins[ 0 ]] + dp[j - coins[ 1 ]] + ... + dp[j - coins[ n ]]种，即dp[ j ] = dp[ j ] + dp[j - coins[ i ]]。（[example可看第四十四天第一题笔记（518. 零钱兑换 II）](../代码随想录算法训练营第四十四天%20|%20518.%20零钱兑换%20II、377.%20组合总和%20Ⅳ.md)）

### 问背包装满最⼤价值：
**dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);**，对应题⽬如下：
- [动态规划：474.⼀和零](https://leetcode.cn/problems/ones-and-zeroes/)
  
### 问装满背包所有物品的最⼩个数：
**dp[j] = min(dp[j - coins[i]] + 1, dp[j]);**，对应题⽬如下：
- 动态规划：322.零钱兑换
- 动态规划：279.完全平⽅数

## 遍历顺序
### 01背包

⼆维dp数组01背包先遍历物品还是先遍历背包都是可以的，且第⼆层for循环是从⼩到⼤遍历。⼀维dp数组01背包只能先遍历物品再遍历背包容量，且第⼆层for循环是从⼤到⼩遍历。⼀维dp数组的背包在遍历顺序上和⼆维dp数组实现的01背包其实是有很⼤差异的，⼤家需要注意！

### 完全背包

说完01背包，再看看完全背包。纯完全背包的⼀维dp数组，先遍历物品还是先遍历背包都是可以的，且第⼆层for循环是从⼩到⼤遍历。但是仅仅是纯完全背包的遍历顺序是这样的，题⽬稍有变化，两个for循环的先后顺序就不⼀样了。如果求组合数就是外层for循环遍历物品，内层for遍历背包。如果求排列数就是外层for遍历背包，内层for循环遍历物品。相关题⽬如下：
- 求组合数：动态规划：518.零钱兑换II
- 求排列数：动态规划：377. 组合总和 Ⅳ、动态规划：70. 爬楼梯进阶版（完全背包）
  
如果求最⼩数，那么两层for循环的先后顺序就⽆所谓了，相关题⽬如下：
- 求最⼩数：动态规划：322. 零钱兑换、动态规划：279.完全平⽅数

对于背包问题，其实递推公式算是容易的，难是难在遍历顺序上，如果把遍历顺序搞透，才算是真正理解了。

# 二、股票问题：递推公式：dp[][]
## 对于可以无限制买入-售出的股票问题
    - dp[i][0]：第i天状态为买入时手中的余额。
      - dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]). 在“第i-1天就已经买入”与“在第i天才买入（此时手中余额等同于第i-1天售出了股票后的余额）”的情况中选择最大值。
    - dp[i][1]：第i天状态为售出时手中的余额。
      - dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i])。在“第i-1天就已经售出”与“在第i天才售出（此时手中余额等同于第i-1天买入股票后的余额）”的情况中选择最大值。
    - 初始化：  
        第0天做第⼀次买⼊的操作，dp[0][1] = -prices[0];  
        第0天做第⼀次卖出的操作，dp[0][2] = 0   

## 对于有限制次数买入-售出的股票问题
    - dp[i][0]：表示不操作
    - dp[i][1]：第⼀次买⼊
      - 达到dp[i][1]状态，有两个具体操作：  
            操作⼀：第i天买⼊股票了，那么dp[i][1] = dp[i - 1][0] - prices[i]  
            操作⼆：第i天没有操作，⽽是沿⽤前⼀天买⼊的状态，即：dp[i][1] = dp[i - 1][1]  
            选最⼤的，所以 dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][0]);
    - dp[i][2]：第⼀次卖出
      - 同理dp[i][2]也有两个操作：  
            操作⼀：第i天卖出股票了，那么dp[i][2] = dp[i - 1][1] + prices[i]  
            操作⼆：第i天没有操作，沿⽤前⼀天卖出股票的状态，即：dp[i][2] = dp[i - 1][2]  
            所以dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2])

    - dp[i][3]：第二次买⼊
    - dp[i][4]：第二次卖出
      - 同理可推出剩下状态部分：  
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);  
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    
    - 初始化：
        第0天没有操作，这个最容易想到，就是0，即：dp[0][0] = 0;  
        第0天做第⼀次买⼊的操作，dp[0][1] = -prices[0];  
        第0天做第⼀次卖出的操作，dp[0][2] = 0  
        第0天第⼆次买⼊操作，初始化为：dp[0][3] = -prices[0];  
        同理第0天第⼆次卖出初始化dp[0][4] = 0
- 更多种状态的股票问题。如果交易股票有次数限制，那么状态数量需要根据具体次数进行调整(2k+1个状态，其中0是未操作，然后是第一次买入、第一次卖出、第二次买入、第二次卖出...第k次买入，第k次卖出)；如果交易没有次数限制，那么状态数量只需设置两个：持有和未持有股票

## 关于有冷却的股票问题（旧解法，五个状态）：

    - 状态一：保持买入：dp[0][0] = -prices[0]; 
      - 状态在前一天已是“保持买入”与前一天为“今天买入”中选择最大：dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
    - 状态二：今天买入：dp[0][1] = -prices[0]; 
      - 状态在前一天是“冷却状态”或者前一天已经是“保持售出”状态中选择最大：dp[i][1] = max(dp[i-1][4] - prices[i], dp[i-1][2] - prices[i]);
    - 状态三：保持卖出：dp[0][2] = 0; 
      - 状态在前一天是”冷却状态”或者前一天是“保持卖出状态”中选择最大（前一天不可能是状态4）：dp[i][2] = max(dp[i-1][4], dp[i-1][2]);
    - 状态四：今天卖出：dp[0][3] = 0; 
      - 状态在前一天是“保持买入状态”或前一天是“今天买入状态”中选择一个：dp[i][3] = max(dp[i-1][1] + prices[i], dp[i-1][0]+prices[i]);
    - 状态五：冷却：dp[0][4] = 0; 
      - 状态只可能是前一天是“今天卖出”状态：dp[i][4] = dp[i-1][3];
    - 初始化：  
        dp[0][0] = -prices[0]; //保持买入  
        dp[0][1] = -prices[0]; //今天买入  
        dp[0][2] = 0; //保持卖出  
        dp[0][3] = 0; //今天卖出  
        dp[0][4] = 0; //冷冻

## 关于有冷却的股票问题（新解法，更简便三个状态）：        
```
1. 定义dp[ i ][ j ]: 表示第i天在状态j时的最大利润
   1. i 表示天数
   2. j表示状态，0持有，1今天之前就已经卖出去了而导致当天未持有，因此明天不会处于冷冻期，2由于今天刚卖完股票而导致当天未持有，明天会处于冷冻期。
2. base case：第一天如果是持有状态，那么最大利润是-prices[ 0 ]，其他两个状态都是0.
3. 递推公式：
   1. 今天持有股票：dp[ i ][ 0 ] = max(dp[ i - 1 ][ 0 ], dp[ i - 1 ][ 1 ] - prices[ i - 1 ]);
      1. 那么前一天要么是已经持有股票：dp[ i - 1 ][ 0 ]
      2. 要么是前一天未持有股票且不处于刚卖完的状态，此时今天的最大利润就是前一天的“未持有股票且不处于刚卖完的状态”的最大利润加今日的股票价格（冷冻期）：dp[ i - 1 ][ 1 ] - prices[ i - 1 ]。
      3. **为什么前一天不能处于刚卖完的状态？** 如果前一天处于刚卖完的状态，那么今天还是冷冻期，无法交易。
   2. 如果今天未持有股票且不处于刚卖完的状态：dp[ i ][ 1 ] = max(dp[ i - 1 ][ 1 ], dp[ i - 1 ][ 2 ])
      1. 那么前一天要么就是未持有股票且也不处于刚卖完的状态；dp[ i - 1 ][ 1 ]
      2. 要么就是未持有股票但是处于刚买完的状态，dp[ i - 1 ][ 2 ]
   3. 如果今天未持有股票且处于刚卖完的状态：dp[ i ][ 2 ] = dp[ i - 1 ][ 0 ] + prices[ i - 1 ];
      1. 那么前一天一定持有股票，今天的最大利润就是前一天的持有股票状态加今天把股票卖掉的钱，dp[ i - 1 ][ 0 ] + prices[ i - 1 ]
   4. 遍历顺序：从前到后遍历
   5. 返回值：我们不确定最后一天是处于刚好卖掉股票的（冷冻）状态还是处于最后一天的前一天就已经卖掉股票的状态，所以从两个之中选一个大的返回，return max(dp[prices.size()][1], dp[prices.size()][2]);
```

# 三、字符串问题：找子序列问题
## 根据是否连续，思路需要调整：
1. 找最长子序列需要注意是否连续，如果不是连续的那么不能只比较 i 与 i - 1，要比较 i 与 [0, i - 1]。比较[300.最长递增子序列 与 674. 最长连续递增序列](../代码随想录算法训练营第五十二天%20|%20300.%20最长递增子序列、674.%20最长连续递增序列、718.%20最长重复子数组.md)

2. 如果不是连续的子序列，那么当两数组不相等时，不能重新从0计算，而要从之前的dp中选一个最大的。比较[1143（不连续）](../代码随想录算法训练营第五十三天%20|%201143.最长公共子序列、1035.不相交的线、53.%20最大子数组和.md)与[718（连续）](代码随想录算法训练营第五十二天%20|%20300.%20最长递增子序列、674.%20最长连续递增序列、718.%20最长重复子数组.md)

# 回文串问题：
## 1.回文子串与回文子序列的区别：
    回⽂⼦串(substring)是要连续的，回⽂⼦序列(subsequence)可不是连续的。

## 2.遍历顺序
    - 如果这矩阵是从上到下，从左到右遍历，那么会⽤到没有计算过的dp[i + 1][j - 1]，也就是根据不确定是不是回⽂的区间[i+1,j-1]，来判断了[i,j]是不是回⽂，那结果⼀定是不对的。所以⼀定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
    - j=i表示考虑了当子序列长度为1的情况。（此时要在遍历前将所有的dp[i][i]设置为1）
    - j=i+1则表示从子序列长度为2开始考虑。

## 3.递推公式：
    - 在判断回文子串的题目中，关键逻辑就是看s[i]与s[j]是否相同。
    1. 如果s[i]与s[j]相同，那么当dp[ i ][ j ]表示长度时， dp[ i ][ j ] = dp[i + 1][j - 1] + 2; 那么当dp[ i ][ j ]表示是否是回文串时， dp[ i ][ j ] = dp[i + 1][j - 1];
    2. 如果s[i]与s[j]不相同，那么当dp[ i ][ j ]表示长度时， dp[ i ][ j ] =  max(dp[i + 1][j], dp[i][j - 1]); 那么当dp[ i ][ j ]表示是否是回文串时， 一定是dp[ i ][ j ] = false;       
        