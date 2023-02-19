# [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)
### 题目：
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

 

示例 1:
```
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
```
示例 2:
```
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
```
示例 3:
```
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
```
 

提示:
```
1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 10^4
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 给intervals数组排序，按左区间右区间均可。此处按左区间。
- 设置rightbound=第一个右区间。从第二个interval开始遍历intervals，
  - 当左区间小于rightbound时，说明有重合，res++。然后将rightbound更新为值更小的那一个右区间。
    - 为什么不更新为大的那一个右区间：假设区间[1,2][1,3][2,3]。如果用max，那么比较完前两个后，rightbound会从2变成3，在比较[2,3]时，res又会+1，最终结果是2，但正确结果是1
  - 当左区间大于等于rightbound时，说明没重合，直接更新rightbound。
    - 假设两个区间中间有空档怎么办？比如[1,2]、[8,9]、[x,y]。当rightbound=9时，会不会有别的区间如[x,y] = [4,5]因为4<9而被误算？->不会。因为如果存在[4,5]那么在排序的时候该区间会被放在[8,9]之前，从而在遍历的时候优先遍历。

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0435.%E6%97%A0%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4.html)

### 难点：
- 贪心思想

### 代码：  
```
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)   return 0;
        sort(intervals.begin(), intervals.end(), cmp);//从小到大排序
        int right_bound = intervals[0][1];
        int res = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < right_bound){//重叠情况
                res++;
                right_bound = min(right_bound, intervals[i][1]);//假设区间[1,2][1,3][2,3]。如果用max，那么比较完前两个后，rightbound会从2变成3，在比较[2,3]时，res又会+1，最终结果是2，但正确结果是1
            }
            else//未重叠情况
                right_bound = intervals[i][1];
        }
        return res;
    }
};
```


# [763. 划分字母区间](https://leetcode.cn/problems/partition-labels/)
### 题目：
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。

 

示例 1：
```
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
```
示例 2：
```
输入：s = "eccbbbbdec"
输出：[10]
```

提示：
```
1 <= s.length <= 500
s 仅由小写英文字母组成
```
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 假设s = "ababcbaca defegde hijhklij"
- 遍历s，用hash table把每个字母最后出现的位置的index存下来。
  - 对于substring “ababcbaca”，在到达最后一个a,b,c之前，一般至少会各个字母分别遍历一次（即使没有也一定会遍历一次a，否则a就不会是该substring的最后一个字母），此时会将这三个字母的最大右边界中的最大的一个保存。（一定会保存a）
  - 遍历的过程中count++，当i遍历到最大的一个最大右边界时，保存substring的长度count，清空count重新算。

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0763.%E5%88%92%E5%88%86%E5%AD%97%E6%AF%8D%E5%8C%BA%E9%97%B4.html)

### 难点：
- 如何找每个substring的临界点？->最大边界值与i相等时，即是临界点。
- 为何一定会找到正确的字母的最大边界值作为临界点？->因为保存的是拥有最大index作为边界值的字母

### 代码：  
```
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        int right = 0, count = 0;
        vector<int> res;
        //记录每个字母出现的最后位置的index
        for(int i = 0; i < s.size(); i++)
            hash[s[i]-'a'] = i;
        
        for(int i = 0; i < s.size(); i++){
            count++;//记录当前substring的长度
            right = max(right, hash[s[i]-'a']);//找到当前substring的最后一个字母的最大右边界。当我们到达这个最大右边界时即可操作。不需要担心找错最大右边界，假设cbaccba。在真正到达abc三个字母的任意一个字母的最大右边界之前，我们肯定会遍历三个字母至少一遍，而在a的最大右边界之前cb的最大右边界虽然可能会出现，但是由于小于a的最大右边界，cb的最大右边界最终不会被保存。
            if(i == right){//当到达最后一个字母的最大右边界时，我们到了临界点，存储substring的长度，然后清空长度
                res.push_back(count);
                count = 0;
            }
        }
        return res;
    }
};
```


# [56. 合并区间](https://leetcode.cn/problems/merge-intervals/)
### 题目：
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：
```
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```
示例 2：
```
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
```
 
提示：
```
1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
- 找重叠区间：
  - 先排序intervals，把第一个interval的右区间设置成第一个rightbound
  - 把第一个区间push进res
  - 遍历数组，从第二个interval开始
    - 如果当前interval的左区间小于等于rightbound，说明有重叠区间，需要合并区间：
      - 先更新rightbound，rightbound在旧rightbound与当前interval的右区间中选大的一个；合并区间时把res的back的有区间变为新的rightbound
    - 如果没有重叠区间，不需要合并区间，直接把当前interval存入res中，然后更新rightbound

[------------>代码随想录题目详解戳这里](https://programmercarl.com/0056.%E5%90%88%E5%B9%B6%E5%8C%BA%E9%97%B4.html)

### 难点：


### 代码：  
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)   return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());//排序区间
        int right = intervals[0][1];//设置rightbound
        res.push_back(intervals[0]);//把第一个数组push进res集

        //遍历数组，从第二个区间开始算
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= right){//如果当前区间的左区间小于rightbound，那么说明有重叠区间
                right = max(right, intervals[i][1]);//更新rightbound
                res.back()[1] = right;//合并区间，把右区间变成rightbound，而非是intervals[i][1]，因为后者可能其实小于rightbound
            }
            else{//如果没有重叠区间
                right = max(right, intervals[i][1]);//更新rightbound
                res.push_back(intervals[i]);//直接存储未重叠的区间
            }
        }
        return res;
    }
};
```