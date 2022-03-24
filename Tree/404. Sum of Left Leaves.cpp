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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);;
    }
    
    int helper(TreeNode* root, bool isLeft)
    {
        if(root == NULL)
            return 0;
        if(isLeft == true && root->left == NULL && root->right == NULL)
            sum += root->val;
        
        helper(root->left, true);
        helper(root->right, false);
        return sum;
    }
};