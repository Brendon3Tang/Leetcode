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
    int getIDX(vector<int> nums){
        int index = 0;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max)
            {
                index = i;
                max = nums[i];
            }
        }
        return index;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        int idx = getIDX(nums);
        TreeNode* root = new TreeNode(nums[idx]);
        
        vector<int> leftNums(nums.begin(), nums.begin() + idx);
        vector<int> rightNums(nums.begin() + idx + 1, nums.end());
        
        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        
        return root;
    }
};