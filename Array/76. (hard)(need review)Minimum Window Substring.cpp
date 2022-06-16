class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> um;
        int left = 0;
        int length = 0;
        int count = 0;
        int res = INT32_MAX;
        int start = 0;
        int end = 0;
        for(auto c : t)
            um[c]++;
        
        for(int right = 0; right < s.size(); right++)
        {
            if(um[s[right]] > 0)
                count++;
            um[s[right]]--;
            if(count == t.size())
            {
                while(left < right && um[s[left]] < 0)
                {
                    um[s[left]]++;
                    left++;
                }
                
                length = right-left+1;
                if(length < res)
                {
                    res = length;
                    start = left;
                    end = right;
                }
            }
        }
        if(res == INT32_MAX)
            return "";
        return s.substr(start,end-start+1);
    }
};