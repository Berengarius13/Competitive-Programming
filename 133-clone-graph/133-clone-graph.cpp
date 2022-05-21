

class Solution {
    void dfs (Node* node, Node* curr, vector<int> &vis, Node * king){
        vis[node->val] = 1;
        
        for(auto cnode: node->neighbors){
            if(king->neighbors[cnode->val] == NULL){
                Node* child = new Node(cnode->val);
                curr->neighbors.push_back(child);
                king->neighbors[cnode->val] = child;
            }
            else{
                curr->neighbors.push_back(king->neighbors[cnode->val]);
            }
        }
        for(int i = 0; i < node->neighbors.size();i ++){
            Node* child = node->neighbors[i];
            Node* curr_child = curr->neighbors[i];
            if(vis[child->val] != 1){
                dfs(child , curr_child , vis, king);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        vector<int> vis(101, 0);
        Node * king = new  Node(-1, vector<Node*> (101, NULL));
        Node* curr = new Node(node->val);
        king->neighbors[node->val] = curr;
        dfs(node, curr, vis, king);
        return curr;
    }
};









































/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/