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
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        return dp(root,mp);
    }
    
    int dp(TreeNode* root,unordered_map<TreeNode*, int> &mp)
    {
        if(root == NULL)
            return 0;
        if(mp.find(root) != mp.end())
            return mp[root];
        
        int case1 = root->val;
        if(root->left != NULL)
        {
            case1 += dp(root->left->left, mp);
            case1 += dp(root->left->right, mp);
        }
        
        if(root->right != NULL)
        {
            case1 += dp(root->right->left, mp);
            case1 += dp(root->right->right, mp);
        }
        
        int case2 = dp(root->left,mp) + dp(root->right, mp);
        
        mp[root] = max(case1,case2);
        return mp[root];
    }
};