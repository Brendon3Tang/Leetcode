class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int right_bound = intervals[0][1];
        int res = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < right_bound)
            {
                res++;
                right_bound = min(right_bound, intervals[i][1]);
            }
            else
                right_bound = intervals[i][1];
        }
        return res;
    }
};
