class Solution {
    vector<string> res;
    bool isValid(string s, int start, int end)
    {
        if(start > end)//假设backtracking中给s的最末尾加了"."，["101.0.23."]，此时i+2就会大于s.size()-1，即start>end。这一个if可以帮我们筛除所以"."在s最末尾的情况
            return false;
        
        if(s[start] == '0' && start != end)
            return false;
        
        int num = 0;
        for(int i = start; i <= end; i++)
        {
            if(s[i] < '0' || s[i] > '9')
                return false;
            num = num*10 +(s[i]-'0');
            if(num > 255)
                return false;
        }
        return true;
    }
    
    void backtracking(string& s, int startIndex, int count)
    {
        if(count == 3)
        {
            if(isValid(s, startIndex, s.size()-1))
                res.push_back(s);
            return;
        }
        
        for(int i = startIndex; i < s.size(); i++)
        {
            if(isValid(s, startIndex, i) == true)
            {
                s.insert(s.begin()+i+1, '.');
                count++;
                backtracking(s, i+2,count);
                count--;
                s.erase(s.begin()+i+1);
            }
            else
                break;
                //continue;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()==0)
            return res;
        backtracking(s,0,0);
        return res;
    }
};