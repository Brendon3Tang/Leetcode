class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> myVec(numRows);
        string res;
        int i = 0;
        while(i < s.size())
        {
            for(int j = 0; j < numRows && i < s.size(); i++, j++)
                myVec[j] += s[i];
            for(int j = numRows-2; j > 0 && i < s.size(); i++, j--)
                myVec[j] += s[i];
        }
        
        for(int i = 0; i < myVec.size(); i++)
            res += myVec[i];
        
        return res;
    }
};