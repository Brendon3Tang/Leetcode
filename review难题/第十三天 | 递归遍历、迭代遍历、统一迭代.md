# [递归遍历](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html)
# [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)
### 题目：
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

### 思路：
递归遍历


### 代码：  
```
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
    void traverse(TreeNode* root, vector<int> &vec){
        if(root == NULL)    return;
        vec.push_back(root->val);
        traverse(root->left, vec);
        traverse(root->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        vector<int> res;
        traverse(root, res);
        return res;
    }
};
```

# [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)
### 题目：
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历。

### 思路：
递归遍历


### 代码：  
```
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
    void traverse(TreeNode* root, vector<int> &vec){
        if(root == NULL)    return;
        traverse(root->left, vec);
        traverse(root->right, vec);
        vec.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        vector<int> res;
        traverse(root, res);
        return res;
    }
};
```



# [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)
### 题目：
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

### 思路：
递归遍历


### 代码：  
```
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
    void traverse(TreeNode* root, vector<int> &vec){
        if(root == NULL)    return;
        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        vector<int> res;
        traverse(root, res);
        return res;
    }
};
```

# [迭代遍历](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html)

# [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)
### 题目：
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

### 思路：
1. 先存入中间节点到栈中
2. 当栈不为空时，使临时节点=stack.top，然后存入value，弹出该中间节点
3. 如果临时节点/stack.top节点存在**右子节点**就把该子节点推入
4. 如果临时节点/stack.top节点存在**左子节点**就把该子节点推入。（**注意顺序不可颠倒，因为只有存入顺序为右左，弹出的顺序才会是前序遍历：中左右，否则是中右左**）
5. 注意：虽然中间节点是最先存入stack的，但是也是最先弹出的。**在存入左节点和右节点之前就会把中间节点弹出**。


### 代码：  
```

```

# [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)
### 题目：
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历。

### 思路：
与前序遍历思路一样，只是存入栈的顺序**从右左变成左右**，这样弹出的顺序才是**中右左**，然后最后reverse成**左右中**就是后序遍历了。


### 代码：  
```
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        vector<int> res;
        TreeNode* cur;

        if(root == nullptr)
            return {};
        myStack.push(root);

        while(!myStack.empty()){
            cur = myStack.top();
            res.push_back(cur->val);
            myStack.pop();
            //存完中后，先存左再存右，使pop出来后顺序为中左右，后面reverse后变成后续遍历：右左中
            if(cur->left) myStack.push(cur->left);
            if(cur->right) myStack.push(cur->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```



# [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)
### 题目：
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

### 思路：
- 返回顺序时左中右
1. 指针首先不断向左下方遍历（当节点不为null或者stack不为空时），并存入沿途的非空节点到stack中。
2. 当指针遍历到空节点时，使cur=stack.top，即回退到上一个非空父节点（叶子节点），并存入该叶子节点的值然后弹出该节点（左中右里的左）。
3. 接着向该叶子节点的右边遍历，由于叶子节点的右下方肯定为空，所以再次使cur=stack.top，此时cur等于叶子节点的父节点，存入该父节点的值然后弹出（左中右里的中）。
4. 接着向该父节点的右边遍历，如果是叶子节点就会重复步骤2，弹出该叶子节点（左中右里的右），否则会从步骤1开始不断重复直到遇到叶子节点


### 代码：  
```
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> myStack;
        //指针首先不断向左下方遍历（当节点不为null或者stack不为空时），并存入沿途的非空节点到stack中。
        while(cur != nullptr || !myStack.empty()){
            if(cur != nullptr){
                myStack.push(cur);
                cur = cur->left;
            }
            else{//当指针遍历到空节点时，使cur=stack.top，即回退到上一个非空父节点，并存入该叶子节点的值然后弹出该节点（左中右里的左）。然后由于叶子节点右边也为空，此时下一次循环会再运行一次else，回退到叶子节点的父节点，然后存入父节点的值并往右遍历该父节点的右节点
                cur = myStack.top();
                res.push_back(cur->val);
                myStack.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
```