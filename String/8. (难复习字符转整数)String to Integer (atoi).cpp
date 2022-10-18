class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        long ret = 0;
        bool flag = false;
        int i = 0;
        //可接受的前缀有空格，+,-，所以单独写出来
        while(s[i] == ' ') ++i;//while写在最前面因为空格只能在最前面，在其他所有位置都会不合法
        if(s[i] == '-') flag = true;
        if(s[i] == '+' || s[i] == '-') ++i; //用if而不是loop是因为“+”或者“-”只能有一个作为前缀，且+/-号之后只能是数字，不能是空格
        //如果前缀是+,-,空格以外的字符，或者既有“+”又有“-”时，以下的循环不会开始
        while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
            ret = ret * 10 + s[i] - '0';
            if(!flag && ret > INT_MAX) return INT_MAX;
            else if(flag && ret-1 > INT_MAX) return INT_MIN;
            ++i;
        }
        return flag?-ret:ret;
    }
};