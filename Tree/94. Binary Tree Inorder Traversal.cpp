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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         helper(root,res);
//         return res;
//     }
    
//     void helper(TreeNode* root, vector<int> &res)
//     {
//         if(root == nullptr)
//             return;
        
//         helper(root->left, res);
//         res.push_back(root->val);
//         helper(root->right,res);
//     }
// };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top(); //返回null节点的上一节点
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};