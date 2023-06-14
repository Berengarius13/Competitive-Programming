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

class Solution {
public:
    Node* dfs(Node* node, unordered_set<int> &visited, unordered_map<int, Node*> &mp){
        if(node == NULL) return NULL;
        visited.insert(node->val);
        Node * x = new Node(node->val);
        mp[node->val] = x;
        vector<Node*> n;
        for(auto cnode : node->neighbors){
            if(visited.find(cnode->val) == visited.end()){
                Node* cur = dfs(cnode, visited, mp);
                if(cur != NULL)n.push_back(cur);
            }
            else{
                n.push_back(mp[cnode->val]);
            }
        }
        
        x->neighbors = n;
        return x;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_set<int> visited;
        unordered_map<int, Node*> mp;
        return dfs(node, visited, mp);
    }
};