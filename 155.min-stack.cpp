/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
/*
 * 要用stack与queue的时候可以先考虑用vector。
 * push_back, pop_back, empty, front, back
 * iterator的定义方式，与iteration语法
 */
class MinStack {
private:
    vector<int> myVector, tmpStack;
    vector<int>::iterator ptr;
public:
    MinStack() {
        myVector.clear();
    }
    
    void push(int val) {
        myVector.push_back(val);
    }
    
    void pop() {
        if(myVector.empty())
            return;
        myVector.pop_back();
    }
    
    int top() {
        if(myVector.empty())
            throw "empty stack";
        
        return myVector.back();
    }
    
    int getMin() {
        int min;
        if(myVector.empty())
            throw "empty stack";
        else
        {   
            min = myVector.front();
            for(ptr = myVector.begin(); ptr < myVector.end(); ptr++)
            {
                if(min > *ptr)
                {   
                    min = *ptr;
                }
            }
            return min;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

