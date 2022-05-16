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
 * logic:递归到最底端再开始翻转树。注意别人精简的sol是怎么写的
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        //我的sol
        /*TreeNode* Ltree, * Rtree, *tmp;
        Ltree = invertTree(root->left);
        Rtree = invertTree(root->right);
        
        if(Ltree == NULL && Rtree == NULL)
            return root;
        
        tmp = Rtree;
        root->right = Ltree;
        root->left = tmp;
        
        return root;    */
        
        //别人的精简sol
        // TreeNode* Ltree = root->left;
        // root->left = invertTree(root->right);
        // root->right = invertTree(Ltree);
        // return root;

        //反转每一个子节点，然后就可以反正整个tree
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};