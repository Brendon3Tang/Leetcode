class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum = 0;
        int curSum = 0;
        int res = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];//用于检查当前idx适不适合当中起点，如果小于0则不适合，idx变到下一位。用+=，否则[3,1,1]，[1,2,2]这种情况时，res会在i=1/i=2时被覆盖
            totalSum += gas[i] - cost[i];
            
            if(curSum < 0)
            {
                res = i + 1;
                curSum = 0;
            }
        }
        if(totalSum >= 0)
            return res;
        else
            return -1;
    }
};