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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        //遍历每一个节点，然后以当前节点为起点开始preorder traverse。
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + preorder(root,targetSum);
    }
    
    //从当前节点开始dfs一直到叶子节点，如果存在等于targetSum的path，count就会+1.
    int preorder(TreeNode* curRoot, int curSum)
    {
        if(curRoot == NULL)
            return 0;
        
        int count = 0;
        if(curRoot->val == curSum)
            count++;
        
        count += (preorder(curRoot->left, curSum - curRoot->val) + preorder(curRoot->right, curSum - curRoot->val));
        
        return count;
    }
};