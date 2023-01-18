# Leetcode
## [第一天/Day 1](./Array/代码随想录算法训练营第一天|%20704.%20二分查找、27.%20移除元素.md)
### 704.二分查找
- 数组为有序数组，同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的，**这些都是使用二分法的前提条件**。   
- 注意开闭区间

### 27.移除元素(双指针)

## [第二天/Day 2](./array/%E4%BB%A3%E7%A0%81%E9%9A%8F%E6%83%B3%E5%BD%95%E7%AE%97%E6%B3%95%E8%AE%AD%E7%BB%83%E8%90%A5%E7%AC%AC%E4%BA%8C%E5%A4%A9%7C%20977.%20%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9%E3%80%81209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%20%E3%80%8159.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.md)
# 977.有序数组的平方 (双指针)
## [977.有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)
### 思路：
- 暴力解法：遍历数组，平方每个元素，然后排序
- ==**双指针解法**==：一头一尾放指针，比较两个指针所在处的元素的平方大小，把大的放入新数组的最后一个index。如果大的是尾，则把尾指针前移，如果大的是头，则把头指针后移。
[------------>代码随想录题目详解戳这里](https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html)

### 代码：  
```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        vector<int> res(nums.size(), 0);
        for(int k = nums.size()-1; k >= 0; k--){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                res[k] = nums[j] * nums[j];
                j--;
            }
            else{
                res[k] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
```

# 209. 长度最小的子数组 (滑动窗口)
## [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)
### 思路：  
#### 滑动窗口思想：
- 窗口内是sum >= target 的长度最小的 连续 子数组。
- 窗口结束位置(end)为for loop的index，每次循环右移一次
- 窗口开始位置则根据题目需要不断右移。 此题右移条件是当sum >= target。

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html)

### 代码：  
```
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int start = 0, end = 0;
        int sum = 0, subLen = 0;

        for(end = 0; end < nums.size(); end++){
            sum += nums[end]; //求出窗口中所有值的sum
            //用while，因为可能需要不断的减少sum的值，比如[2,3,1,2,4,3]数组，在从[1,2,4]到[4,3]时，经历了从[1,2,4]到[2,4,3]再到[4,3]的两次减法运算，只用if无法达成
            while(sum >= target){ 
                subLen = end - start + 1; // 窗口长度
                res = res < subLen ? res : subLen; //更新res
                sum -= nums[start++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};
```

# 59.螺旋矩阵II
## [59.螺旋矩阵II](https://leetcode.cn/problems/spiral-matrix-ii/)
### 思路：  
1. 分奇偶，奇数需要在矩阵中间填入最后一个值 -> mid位置= maxtrix[n/2][n/2]
2. 需提前找到要循环多少圈？->（每一圈/一个循环是：从左到右，从上到下，从右到左，从下到上）-> # of loop = n/2 （3是循环1圈，4、5是循环两圈）
3. 每次循环开始的点在哪里，是否每次循环会变？->startX，startY，每次循环X,Y分别+1
4. 左开右闭：假设每行每列有3个数，从左到右只填2个，从上到下只填2个，从右到左只填2个，从下到上只填2个，最后一个另外填）
5. offset用于实现第四点，即从左到右的循环终止条件是j < n - offset。注意offset在每完成一整圈后（每次while loop结束后）要+1
   
[------------>代码随想录题目详解戳这里](https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html)

### 代码：  
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int mid = n/2;
        int loop = n /2;
        int startX = 0, startY = 0;
        int offset = 1; //代表着假设每行/列有n个数字，则一个for loop只需填入n-1个数字
        int count = 1;
        int i = 0, j = 0;
        //走n/2次大圈
        while(loop--){
            for(j = startY; j < n - offset; j++) //从左到右，注意起始点时startY不是0
                res[startX][j] = count++;
            for(i = startX; i < n - offset; i++) //从上到下，注意起始点时startX不是0
                res[i][j] = count++;
            for(;j > startY; j--)//从右到左
                res[i][j] = count++;
            for(;i > startX; i--)//从下到上
                res[i][j] = count++;
            
            //走完一次大圈之后，startX,startY要+1，因为下一圈的起点位置要变化
            startX++;
            startY++;

            //offset+1，因为下一圈每一行/列要填入的数字减少了一个
            offset++;
        }
        if(n%2) //n%2不等于0时，为true
            res[mid][mid] = count++;
        
        return res;
        
    }
};
```
