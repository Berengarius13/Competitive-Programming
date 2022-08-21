/*
* Treee is rooted and directed
* Make an undirected graph
* Start dfs from burning edge
*/
class Solution {
public:
    unordered_map<int, vector<int>> adjacency_list;
    
    void create_graph(TreeNode* root, int parent){
        if(root == NULL) return;
        int value = root->val;
        if(parent != -1){
            adjacency_list[value].push_back(parent);
            adjacency_list[parent].push_back(value);
        }
        create_graph(root->left, root->val);
        create_graph(root->right, root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        create_graph(root, -1);
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int top = q.front(); q.pop();
                visited.insert(top);
                for(auto node : adjacency_list[top]){
                    if(visited.find(node) == visited.end())
                        q.push(node);
                }
            }
            time++;
        }
        return time-1;
    }
};

























/*

* DFS return max distance from infected node
* On left side calculate method to calculte distance to infected node

class Solution {
public:
    pair<int, int> dfs(TreeNode* node, const int &start){
        if(node == NULL) return {0,0};
        
        auto left = dfs(node->left, start);
        auto right = dfs(node->right, start);
        //if(node->left == NULL && node->right == NULL) return {0,0};
        if(node->val == start){
            return {max(left.first, right.first), 1};
        }
        if(left.second >= 1){
            return {max(right.first+left.second, left.first), left.second+1};
        }
        if(right.second >= 1){
            return {max(left.first+right.second, right.first ), right.second+1};
        }
        
        return {max(left.first, right.first)+1, 0};
    }
    int amountOfTime(TreeNode* root, int start) {
        return dfs(root, start).first;
    }
};
*/