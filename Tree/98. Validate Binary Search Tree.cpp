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
// private:
//     bool res = true;
//     TreeNode* leftMax;
//     TreeNode* rightMin;
//     TreeNode* findLeft(TreeNode* root)
//     {
//         if(root == NULL)
//             return leftMax;
//         if(root->right == NULL)
//             return root; // leftMax = root
//         else
//             leftMax = findLeft(root->right);
        
//         return leftMax;
//     }
    
//     TreeNode* findRight(TreeNode* root){
//         if(root == NULL)
//             return rightMin;
//         if(root->left == NULL)
//             return root; // rightMin = root
//         else
//             rightMin = findRight(root->left);
        
//         return rightMin;
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root == NULL)
//              return res;
//         if(root->right)
//         {
//             if(root->val >= findRight(root->right)->val)
//             {
//                 res = false;
//                 return res;
//             }
//         }
        
//         if(root->left)
//         {
//             if(root->val <= findLeft(root->left)->val)
//             {
//                 res = false;
//                 return res;
//             }
//         }
        
//         isValidBST(root->left);
//         isValidBST(root->right);
//         return res;
 
//     }
// };
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val); // 将⼆叉搜索树转换为有序数组
        traversal(root->right);
 }
public:
    bool isValidBST(TreeNode* root) {
        vec.clear(); // 不加这句在leetcode上也可以过，但最好加上
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            // 注意要⼩于等于，搜索树⾥不能有相同元素
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};