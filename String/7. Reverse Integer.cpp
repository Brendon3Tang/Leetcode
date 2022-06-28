class Solution {
private:
    int getInt(int x){
        int res = 0;
        while(x){
            //If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0
            if(res > INT_MAX/10 || res < INT_MIN/10)//之后还要*10,所以这里与(INT_MAX/10)和(INT_MIN/10)做比较
                return 0;
            int a = x % 10;
            res = res*10 + a;
            x /= 10;
        }
        return res;
    }
public:
    int reverse(int x) {
        if(x == 0)
            return 0;

        int res = 0;
        res = getInt(x);
        
        return res;
    }
};