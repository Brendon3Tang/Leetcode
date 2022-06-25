class Solution {
private:
    void getNext(int *next, string needle){
        int j = 0;//j指针指向前缀
        next[0] = j;//初始化next[0]
        
        //i指针指向后缀
        for(int i = 1; i < needle.size(); i++)
        {
            //如果当前i-1,j-1中无公共前后缀，则next[0：i]一定全等于0，下面j可直接回退至0。如有相等的前后缀,则可以用next[j]不断回退，直到得到公共前后缀为止。（或者可翻掘金笔记）
            while(j > 0 && needle[j] != needle[i])
                j = next[j-1];
            
            //如果相同，则公共前后缀长度+1
            if(needle[i] == needle[j])
                j++;
            
            //更新位置i的公共前后缀长度（next[i]）
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;//j指针指向needle
        
        //i指针指向haystack
        for(int i = 0; i < haystack.size(); i++)
        {
            //如果h[i]与n[j]不匹配，由于h[x:x+i-1]与n[x:x+i-1]是匹配的，则根据next[j-1],j回退到next[j-1]，直到回退到h[i]==n[j]或者j=0为止。
            while(j > 0 && haystack[i] != needle[j])
                j = next[j-1];
            
            //如果匹配，移动j指针到下一个位置
            if(haystack[i] == needle[j])
                j++;
            
            //如果j移动到了needle的末尾的下一位，则代表needle存在与haystack中
            if(j == needle.size())
                return (i-needle.size()+1);
        }
        //for运行完了则说明不存在
        return -1;
    }
};