class Solution {
public:
    typedef vector<vector<int>> graph;
    graph make_graph(int n, vector<vector<int>> &edges){
        graph g(n);
        for(auto &it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        return g;
    }
    int count = 0;
    void dfs(graph &g, int node, vector<int> &vis, int parent){
        
        vis[node] = 1;
        
        for(auto &cnode : g[node]){
            if(vis[cnode] == 0){
                dfs(g, cnode, vis, node);
            }
            else if(cnode != parent && cnode != node){
                count++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n, 0);
        if(connections.size()<n-1) return -1;
        graph g = make_graph(n, connections);
        int connect_comp = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(g, i, vis, -1);
                connect_comp++;
            }
        }
        
        return connect_comp-1;
    }
};