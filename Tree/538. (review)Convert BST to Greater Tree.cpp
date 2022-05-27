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
    int pre = 0;
    void traversal(TreeNode*& root){
        if(root == NULL)
            return;
        traversal(root->right);
        root->val = root->val + pre;
        pre = root->val;
        traversal(root->left);
        return;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return root;
        traversal(root);
        return root;
    }
};