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
 //迭代写法！！！
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* tmp;
        stack<TreeNode*> st;
        vector<int> res;
        
        if(root == NULL)
            return res;
        st.push(root);
        while(!st.empty())
        {
            tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            if(tmp->right != NULL)
                st.push(tmp->right);
            if(tmp->left != NULL)
                st.push(tmp->left);
        }
        return res;
    }
};