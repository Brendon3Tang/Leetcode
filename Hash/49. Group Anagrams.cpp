class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        vector<vector<string>> res;

       //把每一个str排序，同样的str则说明他们是groupAnagrams，放到同一个以该str为key的map中。 
        for(int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(strs[i].begin(),strs[i].end());
            um[strs[i]].push_back(str);
        }
        
        //遍历map，把map中的vector放入res中
        for(auto it : um)
            res.push_back(it.second);
        
        return res;
    }
};