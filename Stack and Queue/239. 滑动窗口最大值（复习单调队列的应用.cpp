class Solution {
    class myQueue{
    public:
        deque<int> dq;
        void push(int val){
            //使队列单调递减：
            //当队列不为空，且要推入的值大于末端元素时，将末端元素弹出，直到要推入的值大小于或等于末端元素为止。（等于的时候也推入因为要保证两个相同的数同时存在于窗口中，否则在之后弹出其中一个数的时候两个数都会被弹出）
            while(!dq.empty() && val > dq.back())
                dq.pop_back();
            dq.push_back(val);
        }

        void pop(int val){
            if(!dq.empty() && val == dq.front())
                dq.pop_front();
        }

        int front(){
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myQueue que;
        vector<int> res;

        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        res.push_back(que.front());
        
        for(int i = k; i < nums.size(); i++){
            que.pop(nums[i-k]);//如果要弹出的值还在que里，则弹出，否则说明它已经（因为不是最大值在push别的值的时候）被弹出
            que.push(nums[i]);//推入当前的值
            res.push_back(que.front());//将front（此时窗口/队列中的最大值）存入res
        }
        return res;
    }
};