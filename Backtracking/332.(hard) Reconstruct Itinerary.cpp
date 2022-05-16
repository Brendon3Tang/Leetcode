class Solution {
private: 
    unordered_map<string, map<string,int>> targets;
    
    bool backtracking(int ticketNum, vector<string> &res){
        if(res.size() == ticketNum+1)
            return true;
        
        //不可以用auto,在第一个参数用const+外面用&使其能够改变targets里的数据。
        //即假设当res.back = JFK, mypair = {ALT, 1} 与 {SFO,1}时。当mypair把{ALT,1}改成{ALT,0}之后，在下层递归中如果res.back = JFK again,此时的mypair = {ALT,0} 与{SFO,1}，而不是{ALT,1} 与{SFO,1}
        for(pair<const string, int>& mypair : targets[res.back()])
        {
            if(mypair.second > 0)
            {
                res.push_back(mypair.first);
                mypair.second--;
                if(backtracking(ticketNum, res))
                    return true;
                mypair.second++;
                res.pop_back();
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        if(tickets.size() == 0)
            return res;
        //可以用auto
        for(vector<string> item : tickets)
            targets[item[0]][item[1]]++;
        
        res.push_back("JFK");
        backtracking(tickets.size(),res);
        return res;
    }
};