/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        
        if(root != NULL)
            que.push(root);
        
        while(!que.empty())
        {
            int curSize = que.size();
            vector<int> vec;
            for(int i = 0; i < curSize; i++)
            {
                Node* tmp = que.front(); 
                que.pop();
                vec.push_back(tmp->val);
                for(auto node : tmp->children)
                    que.push(node);
            }
            res.push_back(vec);
        }
        return res;
    }
};