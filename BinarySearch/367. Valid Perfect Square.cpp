class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0;
        long right = num;
        while(left <= right)
        {
            long mid = left + ((right-left)/2);
            if(mid*mid == num)
                return true;
            if(mid*mid < num)
                left = mid+1;
            else if(mid*mid > num)
                right = mid-1;
        }
        return false;
    }
};