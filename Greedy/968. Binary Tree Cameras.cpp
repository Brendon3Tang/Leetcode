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
//所以我们要从下往上看，局部最优：让叶⼦节点的⽗节点安摄像头，所⽤摄像头最少，整体最优：全部摄像头数量所⽤最少！给定树的节点数的范围是 [1, 1000]。每个节点的值都是 0。
//思路:局部最优推出全局最优，找不出反例，那么就按照贪⼼来！此时，⼤体思路就是从低到上，先给叶⼦节点⽗节点放个摄像头，然后隔两个节点放⼀个摄像头，直⾄到⼆叉树头结点。
// 0：该节点⽆覆盖
// 1：本节点有摄像头
// 2：本节点有覆盖
class Solution {
public:
    int traversal(TreeNode* curr, int &res)
    {
        // 空节点不能是⽆覆盖的状态，这样叶⼦节点就要放摄像头了，空节点也不能是有摄像头的状态，这样叶⼦节点的⽗节点就没有必要放摄像头了，⽽是可以把摄像头放在叶⼦节点的爷爷节点上。所以空节点的状态只能是有覆盖，这样就可以在叶⼦节点的⽗节点放摄像头了
        if(curr == NULL)
            return 2;
        
        int left = 0;
        int right = 0;
        left = traversal(curr->left,res);
        right = traversal(curr->right,res);
        
        //情况1：左右节点都有覆盖。左孩⼦有覆盖，右孩⼦有覆盖，那么此时中间节点应该就是⽆覆盖的状态了。
        if(left == 2 && right == 2)
            return 0;
        //情况2：左右节点⾄少有⼀个⽆覆盖的情况
        else if(left == 0 || right == 0)
        {
            res++;
            return 1;
        }
        //情况3：左右节点⾄少有⼀个有摄像头（且不存在左右节点有无覆盖的情况，因为上面一个if已经判断过)
        else //(left == 1 || right == 1):如果left == 1, right == 0 怎么办？其实这种条件在上一个if中已经判断过了
            return 2;
        
        return -1;//逻辑无法到达
    }
    int minCameraCover(TreeNode* root) {
        int res = 0;
        
        //情况4：root无覆盖
        if(traversal(root,res) == 0)
            res++;
        
        return res;
    }
};