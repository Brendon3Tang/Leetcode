class Solution {
public:
//dp[i][j]:以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最⻓重复⼦数组⻓度为dp[i][j]。 不表示以i,j结尾的A与B，否则nums1[0]与nums2[0]的两个值很难access
//只要nums1[i-1]=nums2[j-1],dp[i][j]=dp[i-1][j-1]+1
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int res = 0;
        for(int i = 1; i < nums1.size()+1; i++)
        {
            for(int j = 1; j < nums2.size()+1; j++)
            {
                if(nums2[j-1] == nums1[i-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                
                if(dp[i][j] > res)
                    res = dp[i][j];
            }
        }
        return res;
    }
};