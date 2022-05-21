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
    TreeNode* traverse(vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size() == 0)
            return NULL;
        
        //1.找到postorder最后一个元素，用来做root
        int rootVal = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootVal);
        
        if(inorder.size() == 1)
            return root;
        
        //2.用postorder这个元素找到inorder中delimiter的位置，切割inorder。
        int delimiter;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == rootVal)
            {
                delimiter = i;//找到delimiter
                break;
            }
        }
        //切割inorder:
        //把index为[0，delimiter-1]的value放进leftInorder。index 为delimiter的value舍弃（因为已成为root）
        //此处表示从index begin()/0开始，保存delimiter个数字进leftInorder
        vector<int> leftInorder(inorder.begin(), inorder.begin()+delimiter);
        
        //把index位[delimiter+1,end]的value放进rightInorder
        //此处表示从index delimiter (即第delimiter+1个位置)开始，一直到结束
        vector<int> rightInorder(inorder.begin() + delimiter + 1,inorder.end());
        
        //3.把postorder的最后一个节点去掉（已经用来找到delimiter且当中root)
        postorder.resize(postorder.size()-1);
        
        //4.用切割后的inorder的元素数量来切割postorder
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());
        
        root->left = traverse(leftInorder, leftPostorder);
        root->right = traverse(rightInorder, rightPostorder);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        if(inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        root = traverse(inorder, postorder);
        return root;
    }
};