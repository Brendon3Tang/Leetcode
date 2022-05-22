/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int,int> m;
    void traverse(TreeNode* root)
    {
        if(root == NULL)
            return;
        m[root->val]++;
        traverse(root->left);
        traverse(root->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        vector<int> mode;
        int maxVal = 0;
        for(auto it : m)
            maxVal = max(it.second, maxVal);
        
        for(auto it : m)
        {
            if(it.second == maxVal)
                mode.push_back(it.first);
        }
        
        return mode;
    }
};