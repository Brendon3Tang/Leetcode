/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
         if(allCap(word) || allLow(word) || firstCap(word))
            return true;
        else
            return false;
    }

    bool allCap(string word)
    {
        if(word == "")
            return false;
        
        char c;
        for(int i = 0; i < word.length(); i++)
        {
            c = word.at(i);
            if(!isupper(c))
                return false;
        }
        return true;
    }
    
    bool allLow(string word)
    {
        if(word == "")
            return false;
        
        char c;
        for(int i = 0; i < word.length(); i++)
        {
            c = word.at(i);
            if(isupper(c))
                return false;
        }
        return true;
    }
    
    bool firstCap(string word)
    {
        if(word == "")
            return false;
        
        char c;
        c = word.at(0);
        if(isupper(c))
        {
            for(int i = 1; i < word.length(); i++)
            {
                c = word.at(i);
                if(isupper(c))
                    return false;
            }
            
            return true;
        }
        
        return false;
        
    }
};
// @lc code=end

