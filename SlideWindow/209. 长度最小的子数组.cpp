class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int start = 0, end = 0;
        int sum = 0, subLen = 0;

        for(end = 0; end < nums.size(); end++){
            sum += nums[end]; //求出窗口中所有值的sum
            while(sum >= target){ //用while，因为可能需要不断的减少sum的值，比如[2,3,1,2,4,3]数组，在从[1,2,4]到[4,3]时，经历了从[1,2,4]到[2,4,3]再到[4,3]的两次减法运算，只用if无法达成
                subLen = end - start + 1; // 窗口长度
                res = res < subLen ? res : subLen; //更新res
                sum -= nums[start++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};