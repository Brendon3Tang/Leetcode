# [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)
### 题目：
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

 

示例 1：
```
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。
```
示例 2：
```
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     总利润为 4 。
```
示例 3：
```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。
```

提示：
```
1 <= prices.length <= 3 * 10^4
0 <= prices[i] <= 10^4
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 由于要找这个时间区间内最高的所有利润总和，所以不能单独找其中一个最高的利润，而要把所有正利润加起来。因此，遍历prices数组，只要利润是正数就把他累加，最后返回累积后的res。


[------------>代码随想录题目详解戳这里](https://programmercarl.com/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII.html)

### 难点：


### 代码：  
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        
        for(int i = 1; i < prices.size(); i++)
            res += max(prices[i]-prices[i-1], 0);
        
        return res;
    }
};
```


# [55. 跳跃游戏](https://leetcode.cn/problems/jump-game/)
### 题目：
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

 

示例 1：
```
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```
示例 2：
```
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
```

提示：
```
1 <= nums.length <= 3 * 10^4
0 <= nums[i] <= 10^5
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
### 思路：
- 不需要纠结是跳一步还是两步还是n步，只需要找出覆盖范围即可
- 定义覆盖范围int cover，每一个位置的cover是当前位置的index+当前位置可以跳跃的数量，而最终需要记录的cover是当前所遍历过的所有位置中可以跳的最远的位置。cover = (nums[i]+i, cover)
- 注意遍历的范围并不是从[0,nums.size()-1]，而是[0,cover]。因为只能遍历到覆盖范围内的数

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.html)

### 难点：
- 遍历的范围并不是从[0,nums.size()-1]，而是[0,cover]。因为只能遍历到覆盖范围内的数

### 代码：  
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1)    return true;
        for(int i = 0; i <= cover; i++){//注意这里是小于等于cover，因为只遍历到当前的覆盖范围为止
            cover = max(nums[i] + i, cover);
            if(cover >= nums.size()-1)   return true;
        }
        return false;
    }
};
```


# [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)
### 题目：
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

- 0 <= j <= nums[i] 
- i + j < n
  
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

 

示例 1:
```
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```
示例 2:
```
输入: nums = [2,3,0,1,4]
输出: 2
```

提示:
```
1 <= nums.length <= 104
0 <= nums[i] <= 1000
题目保证可以到达 nums[n-1]
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 当nums中只有一个数时，无需跳跃，返回0
- 当nums大于一个数时，遍历[0,nums.size()-2/倒数第二个元素]
  - 记录当前元素的可覆盖范围(curCover)，同时记录最大的可覆盖范围longestCover，然后继续向后遍历
  - 在到达第一个元素的覆盖范围末尾(curCover)时，我们res需要+1，表示我们从第一个元素跳向了他覆盖范围中的另一个元素（该元素提供了最大可覆盖范围longestCover)。然后把curCover更新为该元素的覆盖范围。
  - 当i=nums.size-2时，如果curCover=i，说明我们这一步刚好只能够到达nums.size-2，需要从这一步的覆盖范围中选一个可以到达nums.size-1/末尾的元素，即再跳一步。所以res++。；如果curCover != i时，说明curCover > i，那么无需res++，只需等forloop结束return res即可。

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0045.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FII.html)

### 难点：
- 遍历范围是[0,nums.size()-2/倒数第二个元素]
- 什么时候需要跳一步？->到达当前覆盖范围末尾时，如果还没到达数组末尾(i <= nums.size-2而curCover == i时)，则需要跳。
 
### 代码：  
```
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, longestCover = 0, curCover = 0;
        if(nums.size()==1)  return 0;
        //当nums的size不为1时
        for(int i = 0; i <= nums.size()-2; i++){
            longestCover = max(i+nums[i], longestCover);
            //在nums的size不为1的情况下，curCover = 0时一定会使res+1，保证至少跳1步
            if(curCover == i){//由于数组最多只遍历到倒数第二位，这些位置中，当curCover = i时，说明已经到达了上一步所覆盖的最长距离，但还未到达数组末尾。说明我们要在之前遍历过的格子里找到覆盖范围能够通向当前格子之后的格子，并且再跳一次，才有可能到达末尾。找到那个格子之后，更新longestCover
                res++;
                curCover = longestCover;
            }
        }
        return res;
    }
};
```