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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        if(root->left == NULL && root->right == NULL)
            return -1;
        int leftValue = root->left->val;
        int rightValue = root->right->val;
        
        if(leftValue == root->val)
            leftValue = findSecondMinimumValue(root->left);
        if(rightValue == root->val)
            rightValue = findSecondMinimumValue(root->right);
        
        if(leftValue == -1)
            return rightValue;
        if(rightValue == -1)
            return leftValue;
        
        return min(leftValue, rightValue);
    }
};