class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        /*sort(nums.begin(), nums.end());
        while(k > 0)
        {
            k--;
            nums[0] = -nums[0];
            sort(nums.begin(), nums.end());
        }
        int res = 0;
        for(int num : nums)
            res += num;
        return res;*/
        //上面的方法太慢
        
        sort(nums.begin(), nums.end(),cmp);
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        
        if(k % 2 != 0)
            nums[nums.size()-1] = -nums[nums.size()-1];
        
        int res = 0;
        for(int num : nums)
            res += num;
        
        return res;
    }
};