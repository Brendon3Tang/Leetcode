class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return false;
        
        string newStr;
        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] - 'a' < 26 && s[i] - 'a' >= 0) || (s[i] - '0' <= 9 && s[i] - '0' >= 0) ) 
                newStr.push_back(s[i]);
            else if(s[i] - 'A' < 26 && s[i] - 'A' >= 0)
            {
                s[i] += 32;
                newStr.push_back(s[i]);
            }
        }
        
        for(int i = 0, j = newStr.size()-1; i < j; i++, j--)
        {
            if(newStr[i] != newStr[j])
                return false;
        }
        return true;
    }
};