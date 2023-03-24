class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, length = 0;
        unordered_map<char,int> window;
        
        for(int right = 0; right < s.size(); right++)
        {
            if(window.find(s[right]) != window.end() )
            {
                while(window.find(s[right]) != window.end())
                {
                    window.erase(s[left++]);
                }
            }
            
            window[s[right]]++;
            length = max(length, right-left+1);
        }
        return length;
    }
};