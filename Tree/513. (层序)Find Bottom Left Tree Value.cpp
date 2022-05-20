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
    int findBottomLeftValue(TreeNode* root) {
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
        return res[res.size()-1][0];
    }
};

//递归法：
// class Solution {
// private:
//     int deepest = 0;
//     int res = 0;
//     void traverse(TreeNode* root, int depth){
//         if(root == NULL)
//             return;
        
//         if(root->left == NULL && root->right == NULL && depth > deepest)
//         {
//             deepest = depth;
//             res = root->val;
//         }
        
//         traverse(root->left, depth+1);
//         traverse(root->right, depth+1);
//     }
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         if(root->left == NULL && root->right == NULL)
//             return root->val;
//         traverse(root, 1);
//         return res;
//     }
// };