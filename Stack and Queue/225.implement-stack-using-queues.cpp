/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
/*设置两个队列，队列1为空时可直接插入。队列1不为空时，每当需要插入时，需先将所有
在队列1中的元素插入到队列2，然后插入新元素到队列1，最后把队列2中的所有元素重新
插入队列1.*/
class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty())
        {
            q1.push(x);
        }
        else
        {
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(x);

            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        
    }
    
    int pop() {
        int result = 0;
        result = q1.front();
        q1.pop();

        return result;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

