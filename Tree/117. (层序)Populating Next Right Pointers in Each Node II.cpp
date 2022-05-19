/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root == NULL)
            return root;
        que.push(root);
        while(!que.empty())
        {
            int curSize = que.size();
            Node* tmp;
            Node* pre;
            for(int i = 0; i < curSize; i++)
            { 
                tmp = que.front();
                que.pop();
                if(i == 0)
                    pre = tmp; 
                else
                {
                    pre->next = tmp;
                    pre = tmp;
                }
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
            }
        }
        return root;
    }
};