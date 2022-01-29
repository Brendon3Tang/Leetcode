/*
 * @lc app=leetcode id=20 lang=cpp
 * 
 * 思路：iterate字符串，如果是
    情况1：(, {, [ 则直接插入到vector中。如果不是，则
 *  情况2：（")", "]","}"中的任意一种），先检查vector.back()是不是该种括号的左括号，
 *  如果不是则说明不符合要求，return false。如果是，则该括号检查完毕，pop该括号的左括号
 *  情况3：在情况2中，vector是空的话，则说明右括号被首先插入，也不符合要求，return false。
 *  情况4：在情况1中，如果概括号没有被闭合，return false
 * 
 * ps:需要test的特殊case: "(",")", "({)}"
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
private:
    vector<char> strVector;
    string::iterator ptr;
    
public:
    Solution()
    {
        strVector.clear();
    }
    bool isValid(string s) {
        for(ptr = s.begin(); ptr != s.end(); ptr++)
        {
            //直接插入 情况1
            if(*ptr == '(' ||  *ptr == '{' || *ptr == '[')
                strVector.push_back(*ptr);
            else
            {
                //情况2
                if(!strVector.empty())
                {
                    if(*ptr == ')' && strVector.back() != '(')
                        return false;
                    else if(*ptr == '}' && strVector.back() != '{')
                        return false;
                    else if(*ptr == ']' && strVector.back() != '[')
                        return false;
                    else
                        strVector.pop_back();
                }
                else//情况3
                    return false;
            }
        }
        
        //情况4
        if(!strVector.empty())
            return false;

        return true;
    }
};
// @lc code=end

