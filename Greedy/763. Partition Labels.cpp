class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        int right_bound = 0;
        int count = 0;
        vector<int> res;
        
        for(int i = 0; i < s.size(); i++)
            hash[s[i] - 'a'] = i; //获得hash[‘char’]出现时的index 'i'，并存在hash中，当循环结束时，hash['char']储存的就是char出现的最后的index
        
        for(int i = 0; i < s.size(); i++)
        {
            //达到right_bound之前，所以属于当前子串的char都至少会出现一次，所以在（right_bound == i）之前一定可以找到max的right_bound。并且在此之前count要++
            right_bound = max(right_bound, hash[s[i]-'a']);
            count++;
            if(right_bound == i)
            {
                res.push_back(count);
                count = 0;
            }
        }
        return res;
    }
};