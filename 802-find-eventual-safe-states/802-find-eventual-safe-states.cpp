class Solution {
public:
    vector<int> ans;
    int dfs(vector<vector<int>> &graph, int node, vector<int> &vis){
        vis[node] = 1;
        int is_end = 1;
        for(int cnode: graph[node]){
            is_end = 0;
            if(vis[cnode] == 0){
                dfs(graph, cnode, vis);
            }
        }
        vis[node] = 2;
        if(is_end){
            vis[node] = 3;
            cout<<node<<" ";
            ans.push_back(node);
            return 0;
        }
        for(auto &cnode : graph[node]){
            if(vis[cnode] != 3) return 0;
        }
        vis[node] = 3;
        ans.push_back(node);
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            if(vis[i] == 0){
                dfs(graph, i, vis);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};