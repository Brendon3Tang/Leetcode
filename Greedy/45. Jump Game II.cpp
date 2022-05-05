class Solution {
public:
    int jump(vector<int>& nums) {
        int currCover = 0;
        int nextCover = 0;
        int steps = 0;
        if(nums.size() == 1)
            return 0;
        for(int i = 0; i < nums.size(); i++)
        {
            nextCover = max(nums[i]+i, nextCover);
            if(i == currCover)
            {
                steps++;
                currCover = nextCover;
                if(nextCover >= nums.size()-1)
                    return steps;
            }
        }
        return steps;
    }
};