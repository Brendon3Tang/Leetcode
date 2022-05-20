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
// class Solution {
// public:
//     int count = 0;
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root == NULL)
//             return false;
        
//         count += root->val;
//         if(count == targetSum && root->left == NULL && root->right == NULL)
//             return true;
        
//          if(hasPathSum(root->left,targetSum) == true || hasPathSum(root->right,targetSum) == true)
//              return true;
//         count -= root->val;
//         return false;
//     }
    
// };
//自己的回溯算法
class Solution {
private:
    bool flag = false;
    void backtracking(TreeNode* root, int targetSum, int sum)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum + root->val == targetSum)
                flag = true;
            return;
        }
        
        backtracking(root->left, targetSum, sum+root->val);
        backtracking(root->right, targetSum, sum+root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        backtracking(root, targetSum, 0);
        return flag;
    }
};