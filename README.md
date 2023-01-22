# Leetcode
# [第一天/Day 1](./Array/代码随想录算法训练营第一天|%20704.%20二分查找、27.%20移除元素.md)
### 704.二分查找
- 数组为有序数组，同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的，**这些都是使用二分法的前提条件**。   
- 注意开闭区间

### 27.移除元素(双指针)

# [第二天/Day 2](./array/%E4%BB%A3%E7%A0%81%E9%9A%8F%E6%83%B3%E5%BD%95%E7%AE%97%E6%B3%95%E8%AE%AD%E7%BB%83%E8%90%A5%E7%AC%AC%E4%BA%8C%E5%A4%A9%7C%20977.%20%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9%E3%80%81209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%20%E3%80%8159.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.md)
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


# 59.螺旋矩阵II
## [59.螺旋矩阵II](https://leetcode.cn/problems/spiral-matrix-ii/)
### 思路：  
1. 分奇偶，奇数需要在矩阵中间填入最后一个值 -> mid位置= maxtrix[n/2][n/2]
2. 需提前找到要循环多少圈？->（每一圈/一个循环是：从左到右，从上到下，从右到左，从下到上）-> # of loop = n/2 （3是循环1圈，4、5是循环两圈）
3. 每次循环开始的点在哪里，是否每次循环会变？->startX，startY，每次循环X,Y分别+1
4. 左开右闭：假设每行每列有3个数，从左到右只填2个，从上到下只填2个，从右到左只填2个，从下到上只填2个，最后一个另外填）
5. offset用于实现第四点，即从左到右的循环终止条件是j < n - offset。注意offset在每完成一整圈后（每次while loop结束后）要+1
   
[------------>代码随想录题目详解戳这里](https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html)



# [第九天/Day 9](./String/%E4%BB%A3%E7%A0%81%E9%9A%8F%E6%83%B3%E5%BD%95%E7%AE%97%E6%B3%95%E8%AE%AD%E7%BB%83%E8%90%A5%E7%AC%AC%E4%B9%9D%E5%A4%A9%20%7C%2028.%20%E6%89%BE%E5%87%BA%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%8C%B9%E9%85%8D%E9%A1%B9%E7%9A%84%E4%B8%8B%E6%A0%87%E3%80%81459.%20%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md)

## [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)
### 题目：
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
可以看出模式串与前缀表（next)对应位置的数字表示的就是：下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀。
1. 求next数组：
   1. 设置j指向初始位置0，再设置i从==1==开始遍历模式串（needle）。
   2. 当j=0时无需回退，当j>0时，如果s[i]!=s[j]，说明一定不存在相同前缀后缀，用next数组中j-1的位置的数字回退j：j=next[j-1]
   3. 如果s[i]=s[j]，则说明至少存在一个相同长度前缀后缀，j++（如果长度大于1，则j>0, j++后得到的即是长度）
   4. 在for loop结束前填入next[i]=j
2. 比较字符串与模式串：
   1. 如果字符串长度为0，返回0
   2. 定义一个next数组，然后定义j指向初始位置0，定义i从==0==开始遍历（与next数组中的遍历区分）
   3. 比较字符串与模式串（不相等时）：当j=0时无需回退，当j>0时，如果haystack[i] != needle[j]，回退j至next的[j-1]位置所存的值的位置：j=next[j-1]
   4. 比较字符串与模式串（相等时）：j++，移动到needle的下一个位置继续比较
   5. 如果j=needle.size()时（不是size-1，因为之前最后一次比较后仍有一次j++)，说明needle已经比较完毕，说明模式串needle存在于字符串中，返回index = i - j/needle.size() + 1

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html)


## [459. 重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern/)
### 题目：
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

### 思路：
1. 求出s的next数组
2. 条件一：存在重复子串的条件：next数组最后一位的值不等于0
3. 条件二：数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
4. 如果满足上述两个条件，则返回true

   
[------------>代码随想录题目详解戳这里](https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html)



# [第十天/Day 10](./Stack%20and%20Queue/%E4%BB%A3%E7%A0%81%E9%9A%8F%E6%83%B3%E5%BD%95%E7%AE%97%E6%B3%95%E8%AE%AD%E7%BB%83%E8%90%A5%E7%AC%AC%E5%8D%81%E5%A4%A9%20%7C%20232.%20%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97%E3%80%81225.%20%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md)

## [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/)
### 题目：
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-queue-using-stacks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 用两个stack模拟queue。s1是“存stack”，s2是“出stack”
- push逻辑：直接push至s1
- pop/peek：遵循的逻辑是先检查s2是否为空，如果为空则试图存入s1里的**全部**的数，然后把它当成queue；如果不为空则先将s2里的进行操作（pop/peek）

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html)

## [225. 用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/)
### 题目：
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 

注意：

你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- push:直接push
- **pop：把queue中除最后一个元素外的全部头部元素弹出并重新添加到queue末尾，使目标元素变成头部元素，并且弹出**
- top：返回back()
- empty： return queue.empty()

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html)