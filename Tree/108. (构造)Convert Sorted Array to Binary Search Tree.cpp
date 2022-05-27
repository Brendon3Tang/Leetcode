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
    TreeNode* constructBST(vector<int>&nums, int left, int right){
        if(left > right) return NULL;
        int index = left + ((right-left)/2); //如果直接用(left+right)/2会在left=right时出现out of bound的情况
        TreeNode* newNode = new TreeNode(nums[index]);
        newNode->left = constructBST(nums,left,index-1);
        newNode->right = constructBST(nums,index +1,right);
        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = constructBST(nums,0,nums.size()-1);
        return root;
    }
};