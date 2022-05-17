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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root == NULL)
            return res;
        que.push(root);
        while(!que.empty())
        {
            int curSize = que.size();
            TreeNode* tmp;
            int maxValue = INT_MIN;
            for(int i = 0; i < curSize; i++)
            {
                tmp = que.front();
                que.pop();
                if(tmp->val > maxValue)
                    maxValue = tmp->val;
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};