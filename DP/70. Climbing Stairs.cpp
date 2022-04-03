class Solution {
public:
    int climbStairs(int n) {
        //1.base case
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        int pre1, pre2;
        pre1 = 1;
        pre2 = 2;
        int sum = 0;
        for(int i = 3; i <= n; i++)
        {
            sum = pre1 + pre2;
            pre1 = pre2;
            pre2 = sum;
        }
        return sum;
    }
};