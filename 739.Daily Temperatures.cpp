/*
将当天的温度的日期push入stack中。 在每一次push之前，如果1.currentDay的温度低于stack.top的日子的温度，
则将currentDay的日子也放入vector中。否则如果2.currentDay的温度高于stack.top的日子的温度，则找到了stack.top日子的下一个warm day, 
将日期差currentDay-stacktop放入vector days中，然后pop。如果pop后stack不为空，则继续检测currentDay的温度是否高于stack.top的日子的温度，
如果是则重复，不是则将currentDay放入stack中。currentDay++,准备检测下一个currentDay
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //O(N) in the worst case
            /*the worst case (40, 39, 38, 37, 36, 35, 34, 65):  put all the elements
            except 65 into the stack, which takes O(N) time. Then, all calculation 
            will be done in the last day when temperature = 65°F, whichi takes O(N)
            time. Total time is O(2N)=O(N)*/
        vector<int> days(temperatures.size(),0);
        stack<int> myStack;
        
        myStack.push(0); 
        for(int i = 1; i < temperatures.size(); i++)
        {
           while(!myStack.empty() && temperatures[i] > temperatures[myStack.top()])
           {
                days[myStack.top()] = i-myStack.top();
                myStack.pop();
           }
           myStack.push(i);
        }
        return days;
        
        //brute-force checks every slot from j. It is O(N^2) in the worst case
        /*vector<int> days;
        for(int i = 0; i < temperatures.size(); i++)
        {
            if(i == temperatures.size()-1)
                days.push_back(0);
            else
            {   
                for(int j = i + 1; j < temperatures.size();j++)
                {
                    if(temperatures[i] < temperatures[j])
                    {
                        days.push_back(j-i);
                        break;
                    }
                    if(j == temperatures.size()-1)
                        days.push_back(0);
                } 
            }
        }
        return days;*/
    }
};