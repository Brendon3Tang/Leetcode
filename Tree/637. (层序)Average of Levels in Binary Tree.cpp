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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        
        if(root != NULL)
            que.push(root);
        
        while(!que.empty())
        {
            double curSize = que.size();
            vector<int> vec;
            double sum = 0;
            for(int i = 0; i < curSize; i++)
            {
                TreeNode* tmp = que.front(); 
                que.pop();
                sum += tmp->val;
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
            }
            res.push_back(sum/curSize);
        }
        return res;
    }
};