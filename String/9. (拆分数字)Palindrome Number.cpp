class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        vector<int> myV;
        //切割数字
        while(x)
        {
            int sub = x % 10;
            myV.push_back(sub);
            x /= 10;
        }
        
        //判断是否为回文
        for(int i = 0, j = myV.size()-1; i < j; i++,j--)
        {
            if(myV[i] != myV[j])
                return false;
        }
        return true;
    }
};