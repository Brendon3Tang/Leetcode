class Solution {
public:
//改class使priority queue使用map的second来排序，且从大到小排序
class myComparsion{
public:
    bool operator()(const pair<int, int> &l, const pair<int,int> &r){return l.second < r.second;}
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //使用map记录频率
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++)
            myMap[nums[i]]++;
        //使用priority queue对频率进行排序
        priority_queue<pair<int, int>, vector<pair<int,int>>, myComparsion> pq;
        for(auto it : myMap)
            pq.emplace(it.first, it.second);

        //储存结果到vector里
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};