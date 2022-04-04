class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector memo(pairs.size(),1);
        
        if(pairs.size() == 0)
            return 0;
        
        sort(pairs.begin(),pairs.end());
        for(int i = 1; i < pairs.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(pairs[i][0] > pairs[j][1])
                    memo[i] = max(memo[i], memo[j]+1);
            }
        }
        
        int tMax = 0;
        for(int item : memo)
            tMax = max(tMax, item);
        
        return tMax;
    }
};