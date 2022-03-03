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

/*
 * logic: 
 * solution 1：在diameterOfBinaryTree与helperfunction里都递归。在diameterOfBinaryTree里递归到一个节点，并得到当前
 * 节点的左diameter与右diameter，然后把这个节点的左maxLength与右maxLength找出来，如果max(左diameter，右diameter)
 * 小于当前节点的左maxLength+右maxLength，则更新diameter=左maxLength+右maxLength。最好返回该diameter
 * solution 2(推荐): 在helper function里面递归，如果diameter是比当前的左maxLength+右maxLength小，
 * 则更新diameter = 当前的左maxLength+右maxLength。最后返回max(左maxLength,右maxLength)+1
 */

class Solution {
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        //solution 1
        /*if(root == NULL)
            return 0;
       
        int Ldiameter = diameterOfBinaryTree(root->left);
        int Rdiameter = diameterOfBinaryTree(root->right);
        
        int Llength = maxLength(root->left);
        int Rlength = maxLength(root->right);
        
        if(max(Ldiameter, Rdiameter) < Llength + Rlength)
            diameter = Llength + Rlength;
        
        return diameter;*/
        
        //solution 2
        maxLength(root);
        return diameter;
    }
    
    int maxLength(TreeNode* root)
    {
        //solution 1
        /*if(root == NULL)
            return 0;
        
        return max(maxLength(root->left),maxLength(root->right))+1;*/

        //solution 2
        if(root == NULL)
            return 0;
        int left = maxLength(root->left);
        int right = maxLength(root->right);
        diameter = max(diameter, left+right);
        return max(left,right) + 1;
    }
};