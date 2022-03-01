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
    bool result = true;
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        if(isBalanced(root->left) == false) //先检查左子树是否不平衡，如果是则return false,否则检查右子树
            return false;
        
        if(isBalanced(root->right) == false)//在检查右子树是否不平衡，如果是则return false,否则检查root
            return false;
        
        if(abs(maxHeight(root->left) - maxHeight(root->right)) > 1)//检查root是否不平衡
            return false;
        
        return true;
        
    }
    
    int maxHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return (max(maxHeight(root->left),maxHeight(root->right))+1);
    }
};