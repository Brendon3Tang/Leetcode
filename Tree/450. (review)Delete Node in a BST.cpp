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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root; //1.没找到节点
        if(root->val == key)
        {
            if(root->left == NULL && root->right == NULL)//2.目标节点没有子节点
            {
                delete root;
                return NULL;
            }
            else if(root->left == NULL) //3.目标节点无左子节点
            {
                TreeNode* tmp = root->right;
                root->right == NULL;
                delete root;
                return tmp;
            }
            else if(root->right == NULL) //4.目标节点无右子节点
            {
                TreeNode* tmp = root->left;
                root->left == NULL;
                delete root;
                return tmp;
            }
            else //5.目标节点有两个子节点
            {
                TreeNode* curr = root;
                curr = root->right;
                while(curr->left != NULL)
                    curr = curr->left;
                
                TreeNode* tmp = root;
                curr->left = root->left;
                root = root->right;
                delete tmp;
            }
        }
        
        if(root->val > key)
            root->left = deleteNode(root->left,key);
        else if (root->val < key)
            root->right = deleteNode(root->right,key);
        return root;
    }
};