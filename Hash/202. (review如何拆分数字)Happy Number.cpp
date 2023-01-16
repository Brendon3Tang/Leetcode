class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            //例：19。 sum=9*9, n = 19/10 = 1 -> sum = 1*1, n = 1/10 = 0 -> while结束, sum = 82。
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};