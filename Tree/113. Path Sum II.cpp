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
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(TreeNode* root, int targetSum)
    {
        if(root->left == NULL && root->right == NULL && targetSum-root->val == 0)
        {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        
        if(root->left)
        {
            backtracking(root->left, targetSum-root->val);
            path.pop_back();
        }
        if(root->right)
        {
            backtracking(root->right, targetSum-root->val);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return res;
        backtracking(root, targetSum);
        return res;
    }
};