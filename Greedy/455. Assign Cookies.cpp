class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0)
            return 0;
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int res = 0;
        int idx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(idx < g.size() && s[i] >= g[idx])
            {
                res++;
                idx++;
            }
        }
        return res;
    }
};