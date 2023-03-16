// 动态规划
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         vector<int> leftHeight(height.size(), 0), rightHeight(height.size(), 0);
//         vector<int> rain(height.size(), 0);

//         leftHeight[0] = height[0];
//         for(int i = 1; i < height.size(); i++){
//             leftHeight[ i ] = max(leftHeight[i-1], height[i]);
//         }

//         rightHeight[height.size()-1] = height[height.size()-1];
//         for(int i = height.size()-2; i >= 0; i--)
//             rightHeight[ i ] = max(height[i], rightHeight[i+1]);
        
//         int sum = 0;
//         for(int i = 0; i < height.size(); i++){
//             rain[i] = min(leftHeight[i], rightHeight[i]) - height[i];
//             if(rain[i] > 0)
//                 sum += rain[i];
//         }

//         return sum;
//     }
// };

// 单调栈
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int sum = 0;
        st.push(0);

        for(int i = 1; i < height.size(); i++){
            if(height[i] < height[st.top()])
                st.push(i);
            else if(height[i] == height[st.top()]){
                st.pop();
                st.push(i);
            }
            else{
                while(!st.empty() && height[i] > height[st.top()]){
                    int mid = st.top(); //记录要计算的柱子的height的index
                    st.pop();//pop要计算的柱子的index，得到要计算的柱子的左柱子的index为stack top
                    if(!st.empty()){//由于上面pop之后这里还有操作，因此在操作之前需要判断st是否为空。否则在最后一次pop（index 0）之后，st就会变成空，无法进行下面的运算。
                        int w = i - st.top() - 1;
                        int h = min(height[i], height[st.top()]) - height[mid];
                        sum += w * h;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};