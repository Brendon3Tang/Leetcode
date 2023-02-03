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
/*
 * logic:在每一次递归时，为当前层新建一个节点，节点的val=root->val + root2->val。然后进入到下一层，如果root2不存在，则返回root1；
 * 如果root1不存在，则返回root2；如果都不存在则返回NULL
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return NULL;
        if(root1 == NULL && root2 != NULL)
            return root2;
        if(root1 != NULL && root2 == NULL)
            return root1;
           
        TreeNode* root = new TreeNode(root1->val+root2->val);
        
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);

        return root;
    }
};