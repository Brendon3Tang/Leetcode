/*class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int up = 1;
        int down = 1;
        
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] < nums[i+1])
                up = down + 1;
            else if(nums[i] > nums[i+1])
                down = up + 1;
        }
        return max(up,down);
    }
};*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前⼀对差值
        int preDiff = 0; // 前⼀对差值
        int result = 1; // 记录峰值个数，序列默认序列最右边有⼀个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};