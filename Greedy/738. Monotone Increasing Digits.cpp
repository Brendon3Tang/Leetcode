class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int res = 0;
        int flag = str.size();
        //要倒叙遍历，否则像332这样的数的output会变成329
        for(int i = str.size()-1; i > 0; i--)
        {
            if(str[i-1] > str[i])
            {
                flag = i;
                str[i-1]--;
            }
        }

        //不能直接再上面的for loop里面改，否则像100、200、8100这样的数的output会变成90，190，8090
        for(int i = flag; i < str.size(); i++)
            str[i] = '9';
        
        res = stoi(str);
        return res;
    }
};