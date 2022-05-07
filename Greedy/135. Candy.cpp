/*
这道题⽬⼀定是要确定⼀边之后，再确定另⼀边，例如⽐较每⼀个孩⼦的左边，然后再⽐较右边，如果两边⼀起考虑⼀定会顾此失彼。
先确定右边评分⼤于左边的情况（也就是从前向后遍历）
此时局部最优：只要右边评分⽐左边⼤，右边的孩⼦就多⼀个糖果，全局最优：相邻的孩⼦中，评分⾼的右孩⼦获得⽐左边孩⼦更多的糖果
局部最优可以推出全局最优。
如果ratings[i] > ratings[i - 1] 那么[i]的糖 ⼀定要⽐[i - 1]的糖多⼀个，所以贪⼼：candyVec[i] = candyVec[i - 1] + 1。

再确定左孩⼦⼤于右孩⼦的情况（从后向前遍历）
遍历顺序这⾥有同学可能会有疑问，为什么不能从前向后遍历呢？
因为如果从前向后遍历，根据 ratings[i + 1] 来确定 ratings[i] 对应的糖果，那么每次都不能利⽤上前⼀次的⽐较结
果了。（candyNum[i]要根据candyNum[i+1]得出，但如果从前向后遍历，计算candyNum[i]时将会用到还没有准确结果的的candyNum[i+1]！）
所以确定左孩⼦⼤于右孩⼦的情况⼀定要从后向前遍历！
如果 ratings[i] > ratings[i + 1]，此时candyVec[i]（第i个⼩孩的糖果数量）就有两个选择了，⼀个是candyVec[i +
1] + 1（从右边这个加1得到的糖果数量），⼀个是candyVec[i]（之前⽐较右孩⼦⼤于左孩⼦得到的糖果数量）。
那么⼜要贪⼼了，局部最优：取candyVec[i + 1] + 1 和 candyVec[i] 最⼤的糖果数量，保证第i个⼩孩的糖果数量即
⼤于左边的也⼤于右边的。全局最优：相邻的孩⼦中，评分⾼的孩⼦获得更多的糖果。
局部最优可以推出全局最优。
所以就取candyVec[i + 1] + 1 和 candyVec[i] 最⼤的糖果数量，candyVec[i]只有取最⼤的才能既保持对左边
candyVec[i - 1]的糖果多，也⽐右边candyVec[i + 1]的糖果多。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        vector<int> candyNum(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1])
                candyNum[i] = candyNum[i-1] + 1;
        }
        
        for(int i = ratings.size()-2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i+1])
                candyNum[i] = max(candyNum[i+1] + 1, candyNum[i]);
        }
        
        for(int candy : candyNum)
            res += candy;
        return res;
    }
};
//[1,2,87,87,87,2,1]
//1 2 3 1 1 1 1
//1 2 3 1 3 2 1