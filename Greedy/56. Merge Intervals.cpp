class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        queue<vector<int>> q;
        vector<vector<int>> res;
        
        q.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= q.back()[1])
                q.back()[1] = max(intervals[i][1],q.back()[1]);
            else
                q.push(intervals[i]);
        }
        
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};