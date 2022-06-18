class Solution {
public:
    string reverseStr(string s, int k) {
        //i+=2*k即达到reverse the first k characters for every 2k characters的效果
        for(int i = 0; i < s.size(); i += 2*k)
        {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            //这两个条件可同时转化为当剩余字符大于等于k个的情况
            if(i+k <= s.size())
            {
                reverse(s.begin()+i, s.begin()+i+k);
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin()+i, s.end());
        }
        return s;
    }
};