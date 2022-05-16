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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        
        if(root != NULL)
            que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = que.front(); 
                que.pop();
                vec.push_back(tmp->val);
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};