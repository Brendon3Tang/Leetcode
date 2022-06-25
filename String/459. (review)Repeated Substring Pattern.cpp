/*
最长相等前后缀的长度为：next[len - 1] + 1。(这里的next数组是以统一减一的方式计算的，因此需要+1)

数组长度为：len。

如果len % (len - (next[len - 1] + 1)) == 0 ，则说明 (数组长度-最长相等前后缀的长度) 正好可以被 数组的长度整除，说明有该字符串有重复的子字符串。

数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
*/
class Solution {
private:
    void getNext(int* next, string s){
        int j = 0;
        next[0] = 0;
        
        for(int i = 1; i < s.size(); i++)
        {
            while(j > 0 && s[j] != s[i])
                j = next[j-1];
            
            if(s[j] == s[i])
                j++;
            
            next[i] = j;
        }
    }
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0 || s.size() == 1)
            return false;
        
        int next[s.size()];
        getNext(next,s);
        
        int arraySize = s.size();
        int len = 0;
        len = arraySize - next[s.size()-1];
        
        //如果可以整除且next最后一个不为0.（abac可以整除但不符合要求，用next[size-1]!=0来剔除这种情况）
        if(s.size() % len == 0 && next[s.size()-1] != 0)
            return true;
        
        return false;
    }
};