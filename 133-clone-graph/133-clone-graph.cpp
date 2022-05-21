

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
        vector<Node*> neighbor; // Initialize adjacent node list for simplification
        Node* curr = new Node(node->val); // New node,
        mp[node] = curr; // Map it, it's done, no need to compute again and again
        // We need to add neigbors in it, all of Node neighbouts
        for(auto &cnode : node->neighbors){
            // Check if it is already created or not
            if(mp.find(cnode) != mp.end()){ // Its found
                neighbor.push_back(mp[cnode]);
            }
            else{ // Node found we need to create it and it's neighbor
                Node* get_frm_dfs = dfs(cnode, mp);
                neighbor.push_back(get_frm_dfs);
            }
        }
        curr->neighbors = neighbor; // We add all the neighbors
        return curr;  
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        // Return version
        return dfs(node, mp);
    }
};
/*


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

*/

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