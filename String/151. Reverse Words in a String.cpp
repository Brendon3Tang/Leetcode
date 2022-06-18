class Solution {
public:
    string str;
    string reverseWords(string s) {
        stack<string> myStack;
        for(int i = 0; i < s.size(); i++)
        {
            //在最后一个位置时，如果不是空格，最需要收手动更新str最后一个char并手动存入最后一个str
            if(i == s.size()-1 && s[i] != ' ')
            {
                str += s[i];
                myStack.push(str);
            }
            //如果当前char为空格，考虑是否存入stack
            if(s[i] == ' ')
            {
                //string开头如果是空格，不存入stack
                if(i != 0)
                    myStack.push(str);
                //每当遇见空格使，使用while去除重复空格，并把index放到最后一个空格处
                while(s[i+1] == ' ')
                    i++;
                //如果该空格不在string的开头（myStack不为空）与末尾（i!=s.size-1），则存入这个空格
                if(!myStack.empty() && i != s.size()-1)
                {
                    string space;
                    space.push_back(s[i]);
                    myStack.push(space);
                }
                //清空临时的str
                str.clear();
            }
            //如果当前char不是空格，则更新str直到遇到空格
            else
                str += s[i];
        }
        string res;
        while(!myStack.empty())
        {
            res += myStack.top();
            myStack.pop();
        }
        
        return res;
    }
};