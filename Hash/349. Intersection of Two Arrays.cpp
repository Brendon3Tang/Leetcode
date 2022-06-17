class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> um;
        unordered_set<int> mySet;
        for(int i = 0; i < nums1.size(); i++)
            um[nums1[i]] = true;
        
        for(int i = 0; i < nums2.size(); i++)
        {
            if(um[nums2[i]] == true)
                mySet.insert(nums2[i]);
        }
        
        vector<int> res(mySet.begin(),mySet.end());
        
        return res;
    }
};