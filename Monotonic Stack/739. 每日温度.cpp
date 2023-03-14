class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);    //记录结果数组，全部初始化为0

        stack<int> st;  //单调栈，用于存储遍历过的温度的index
        st.push(0);
        for(int i = 0; i < temperatures.size(); i++){
            if(temperatures[i] < temperatures[st.top()])
                st.push(i);
            else if(temperatures[i] == temperatures[st.top()])
                st.push(i);
            else{//if temperatures[i] > st.top()
                while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

//  精简版本
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> res(temperatures.size(), 0);    //记录结果数组，全部初始化为0

//         stack<int> st;  //单调栈，用于存储遍历过的温度的index
//         st.push(0);
//         for(int i = 0; i < temperatures.size(); i++){
//             while(!st.empty() && temperatures[i] > temperatures[st.top()]){
//                 res[st.top()] = i - st.top();
//                 st.pop();
//             }
//             st.push(i);
//         }
//         return res;
//     }
// };