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
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return false;
        
        return helper(root->left,root->right);
    }
    
    bool helper(TreeNode* leftRoot, TreeNode* rightRoot)
    {
        if(leftRoot == NULL && rightRoot == NULL)
            return true;
        if(leftRoot == NULL || rightRoot == NULL)
            return false;
        if(leftRoot->val != rightRoot->val)
            return false;
        return helper(leftRoot->left,rightRoot->right) && helper(leftRoot->right, rightRoot->left);
    }
};