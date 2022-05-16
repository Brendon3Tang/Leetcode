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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root == NULL)
            return res;
        que.push(root);
        
        while(!que.empty())
        {
            int curSize = que.size();
            for(int i = 0; i < curSize; i++)
            {
                if(i == curSize-1)
                    res.push_back(que.front()->val);
                
                TreeNode* node = que.front();
                que.pop();
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
        }
        return res;
    }
};