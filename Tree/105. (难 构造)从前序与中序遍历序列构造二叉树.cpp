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
    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder){
        if(inorder.size() == 0)
            return nullptr;
        //1.找到钱序数组里的root并用此构建新root节点
        int preRoot = preorder[0];//preorder数组里的root是数组里的第一个值
        TreeNode* newRoot = new TreeNode(preRoot);
    
        //2.找到中序数组的切割位置
        int delimiter = 0;
        for(delimiter = 0; delimiter < inorder.size(); delimiter++){
            if(inorder[delimiter] == preRoot)
                break;
        }

        //3.切割中序数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiter);
        vector<int> rightInorder(inorder.begin()+delimiter+1, inorder.end());
     
        //4.切割前序数组
        preorder.erase(preorder.begin());
        vector<int> leftPreorder(preorder.begin(), preorder.begin()+leftInorder.size());
        vector<int> rightPreorder(preorder.begin()+leftInorder.size(), preorder.end());
        newRoot->left = traverse(leftPreorder,leftInorder);
        newRoot->right = traverse(rightPreorder,rightInorder);
        
        return newRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0 && preorder.size() == 0)
            return nullptr;
        TreeNode* root = traverse(preorder, inorder);
        return root;
    }
};