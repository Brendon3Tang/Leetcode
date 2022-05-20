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
private:
    int getMax(Node* root){
        if(root == NULL)
            return 0;
        
        int depth = 1;
        for(auto child : root->children)
            depth = max(depth, getMax(child)+1);
        
        return depth;
    }
public:
    int maxDepth(Node* root) {
        return getMax(root);
    }
};