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
    int path = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return path;
    }
    
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = dfs(root->left); //找到左子树的最长path()
        int right = dfs(root->right);//找到右子树的最长path()
        int leftPath = root->left != NULL && root->left->val == root->val ? left+1 : 0; //如果存在左节点且左节点与本节点curRoot的值相同，则算上curRoot的全部左path=左节点的path+1
        int rightPath = root->right != NULL && root->right->val == root->val ? right+1 : 0;//如果存在右节点且右节点与本节点curRoot的值相同，则算上curRoot的全部右path=右节点的path+1
        path = max(path, leftPath+rightPath); //需要在solution函数里return的path的值是：之前的path与(leftPath+rightPath)中较大的一个
        return max(leftPath, rightPath);//返回算上curRoot的左path与算上curRoot的右path中较长的一个。不考虑leftPath+rightPath作为子path的情况，所以不用与leftPath+rightPath比较。
    }
};