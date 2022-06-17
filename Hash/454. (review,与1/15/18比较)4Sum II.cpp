/*
    本题是使用哈希法的经典题目，而15.三数之和 (opens new window)，18.四数之和 (opens new window)并不合适使用哈希法，因为三数之和和四数之和这两道题
目使用哈希法在不超时的情况下做到对结果去重是很困难的，很有多细节需要处理。
    而这道题目是四个独立的数组，只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，不用考虑有重复的四个元素相加等于0的情况，所以相对于题目18. 四数之和，
题目15.三数之和，简单了不少。

本题解题步骤：
1.首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
2.遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
3.定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
4.在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
5.最后返回统计值 count 就可以了
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> um;
        int count = 0;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
                um[nums1[i]+nums2[j]]++;
        }
        
        for(int i = 0; i < nums3.size(); i++)
        {
            for(int j = 0; j < nums4.size(); j++)
            {
                if(um.find(0-nums3[i]-nums4[j]) != um.end())
                    count += um[0-nums3[i]-nums4[j]];//不是++！
            }
        }
        return count;
    }
};