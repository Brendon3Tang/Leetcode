/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
/*
 * 1.要用stack与queue的时候可以先考虑用vector。
 *      -push_back, pop_back, empty, front, back
 *      -iterator的定义方式，与iteration语法。
 * 2.最快的方法是在push的时候就比较min大小并且更新minimum value（如果是第一次push则不需要比较），
 *   在pop的时候如果pop的刚好是最小值，则也需要更新。
 */
class MinStack {
private:
    vector<int> myVector;
    vector<int>::iterator ptr;
     int min = 0;
public:
    MinStack() {
        myVector.clear();
        min = 0;
    }
    
    void push(int val) {
        if(myVector.empty())
        {
            myVector.push_back(val);
            min = val;
        }
        else
        {
            myVector.push_back(val);
            if(min > val)
                min = val;
        }
    }
    
    void pop() {
        if(myVector.empty())
        {
            return;
        }
        
        if(min == myVector.back())
        {
            myVector.pop_back();
            min = myVector.front();
            for(ptr = myVector.begin(); ptr < myVector.end(); ptr++)
            {
                if(min > *ptr)
                {   
                    min = *ptr;
                }
            }
        }
        else
            myVector.pop_back();
    }
    
    int top() {
        if(myVector.empty())
            throw "empty stack";
        
        return myVector.back();
    }
    
    int getMin() {
        if(myVector.empty())
            throw "empty stack";
        else 
            return min;
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

