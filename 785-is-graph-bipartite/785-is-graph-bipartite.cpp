class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node,vector<bool> &vis, vector<bool> &color, bool black)
    {
        vis[node] = 1;
        color[node] = black; black = !black;
        
        for(auto &cnode : graph[node]){
            if(vis[cnode] == 0){
                if(dfs(graph, cnode, vis, color, black)) return true;
            }
            else if(cnode != node){
                if(color[node] == color[cnode])
                    return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> color (graph.size(), false);
        vector<bool> vis(graph.size(), false);
        for(int i = 0; i < graph.size(); i++){
            if(vis[i] == 0)
                if(dfs(graph, i, vis, color, false)) return false;
        }
        return true;
    }
};