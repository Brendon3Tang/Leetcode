class Solution {
public:
    int mySqrt(int x) {
        long left = 0;
        long right = x;
        int res = 0;
        while(left <= right)
        {
            long mid = left + ((right-left)/2);
            if(mid*mid < x)
            {
                left = mid + 1;
                res = mid;
            }
            else if (mid*mid > x)
                right = mid - 1;
            else 
                return mid;
        }
        return res;
    }
};