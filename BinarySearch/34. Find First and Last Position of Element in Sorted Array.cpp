class Solution {
private:
    int getRightBound(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        int rightBound = -2;
        
        while(left <= right)
        {
            int middle = left + ((right-left)/2);
            if(nums[middle] > target)
                right = middle - 1;
            else
            {
                left = middle + 1;
                rightBound = left;
            }
        }
        return rightBound;
    }
    
    int getLeftBound(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        int leftBound = -2;
        
        while(left <= right)
        {
            int middle = left + ((right-left)/2);
            if(nums[middle] < target)
                left = middle + 1;
            else
            {
                right = middle - 1;
                leftBound = right;
            }
        }
        return leftBound;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBound = getLeftBound(nums,target);
        int rightBound = getRightBound(nums,target);
        
        if(leftBound == -2 || rightBound == -2)
            return {-1,-1};
        
        if(rightBound - leftBound > 1)
                return {leftBound+1,rightBound-1};
        
        return {-1,-1};
    }
};