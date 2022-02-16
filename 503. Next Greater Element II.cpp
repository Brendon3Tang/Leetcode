/*
* 逻辑与739类似。但是
* 1.当比current Num大的数字在current Num之前（index小于current Num的index时），需要一直返回到队列头部，从新开始找。
* 2.最多只需要返还队列头部并从新寻找一次，一定能找到比current Num大的数字，如果没有的话说明current Num是最大的数字。 并且此次到达队尾时，
* 我们一定已经得到了所有数字的答案，因此可以结束查找。
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> elements(nums.size(),-1);
        vector<int> flag(nums.size()+1,0);
        stack<int> st;
        
        st.push(0);
        flag[0] = 1;
        int i = 1;
        while(i != nums.size())
        {
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                elements[st.top()] = nums[i];
                st.pop();
            }
            //如果flag为1，说明此时我们已经返回了队列头部一次，并且开始了重新查找
            if(flag[i] == 0)
            {
                st.push(i);
                flag[i] = 1;
            }

            i = (i+1) % nums.size();

            if(i == 0 && flag[nums.size()] == 1)
            {
                i = nums.size();
            }
            if(i == 0)
                flag[nums.size()] = 1;
            
        }
        return elements;
    }
};