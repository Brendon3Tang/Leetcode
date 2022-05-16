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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> path;
        if(root == NULL)
            return res;
        
        path.push(root);
        while(!path.empty())
        {
            vector<int> vec;
            int runtime = path.size();
            for(int i = 0; i < runtime; i++)
            {
                vec.push_back(path.front()->val);
                
                if(path.front()->left != NULL)
                    path.push(path.front()->left);
                if(path.front()->right != NULL)
                    path.push(path.front()->right);
            
                path.pop();
            }
            res.push_back(vec);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};