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
    void traverse(TreeNode* root, vector<int>& vec)
    {
        if(root == NULL)
            return;
        
        traverse(root->left,vec);
        vec.push_back(root->val);
        traverse(root->right,vec);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        traverse(root,vec);
        int minVal = INT_MAX;
        //sort(vec.begin(),vec.end());
        for(int i = 0; i < vec.size()-1;i++)
            minVal = min(minVal,vec[i+1] - vec[i]);
        return minVal;
    }
};