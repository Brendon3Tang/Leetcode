class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        st.push(0);
        int maxArea = 0;

        for(int i = 1; i < heights.size(); i++){
            if(heights[i] > heights[st.top()])
                st.push(i);
            else if(heights[i] == heights[st.top()])
                st.push(i);
            else{
                while(!st.empty() && heights[i] < heights[st.top()]){
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int width = i - st.top() - 1;
                        int height = heights[mid];
                        int curArea = width * height;
                        if(curArea > maxArea)
                            maxArea = curArea;
                    }
                }
                 st.push(i);
            }
        }
        return maxArea;
    }
};