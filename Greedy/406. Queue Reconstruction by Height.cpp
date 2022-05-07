class Solution {
    
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) 
            return a[1] < b[1];
        return a[0] > b[0];
 }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        list<vector<int>> que;
        int position = 0;
        for(int i = 0; i < people.size(); i++)
        {
            position = people[i][1];
            list<vector<int>>::iterator it = que.begin();
            while(position--)
                it++;
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(),que.end());
    }
};
