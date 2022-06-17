class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) 
                return res;
            
            //去重，如果第i个数和第i-1个数相等，说明已经为第i个数找过了所有的可能情况
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            // 不能用错误去重方法，将会漏掉-1,-1,2/-2,-2,4 这类情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            
            int left = i + 1;
            int right = nums.size()-1;
            
            while(left < right)
            {
                //当三数之和小于0，说明需要再大一点的数，left++，
                if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                    //用while把left加到与当前数大的数。如果不用while，只把left+1，+1后的数可能和原来的数相等。如-1,-1,0。当left在第一个-1时，只加一次可能还是-1
                    while(left < right && nums[left] == nums[left-1]) left++;
                }
                //当三数之和大于0，说明需要再小一点的数，right--，
                else if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                    //同理用while使right左移到一定比原数小的数
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                //当三数之和等于0，push，left++，right--，双指针同时收缩，找别的可能组合
                else
                {
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        
        return res;
    }
};