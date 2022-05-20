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
private:
    vector<string> res;
    vector<int> path;
    void backtracking(TreeNode* root)
    {
        if(root == NULL)
            return; 
        
        if(root->left == NULL && root->right == NULL)
        {
            string s;
            path.push_back(root->val);
            for(int i = 0; i < path.size()-1; i++)
            {
                s += to_string(path[i]);
                s+= "->";
            }
            s += to_string(path[path.size()-1]);
            res.push_back(s);
            return;
        }
        
        path.push_back(root->val);
 
        if(root->left != NULL)
        {   
            backtracking(root->left);
            path.pop_back();
        }
        if(root->right != NULL)
        {
            backtracking(root->right);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return res;
        backtracking(root);
        return res;
    }
};