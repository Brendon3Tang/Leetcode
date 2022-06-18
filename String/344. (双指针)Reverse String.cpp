class Solution {
public:
    void reverseString(vector<char>& s) {
//         stack<char> myStack;
//         for(auto word : s)
//             myStack.push(word);
        
//         for(int i = 0; i < s.size(); i++)
//         {
//             s[i] = myStack.top();
//             myStack.pop();
//         }
        for(int i = 0, j = s.size()-1; i < s.size()/2; i++,j--)
            swap(s[i],s[j]);
    }
};