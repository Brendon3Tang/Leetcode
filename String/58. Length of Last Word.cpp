class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            else if (i > 0 && s[i-1] == ' ' && s[i] != ' ')
                res = 1;
            else
                res++;
        }
        return res;
    }
};