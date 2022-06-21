class Solution {
public:
    typedef vector<vector<int>> graph;
    graph make_graph(vector<vector<int>> &matrix){
        graph g(matrix.size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        return g;
    }
    void dfs(graph &g, int node, vector<int> &vis){
        vis[node] = 1;
        
        for(auto &cnode : g[node])
            if(vis[cnode] == 0)
                dfs(g, cnode, vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        graph g = make_graph(isConnected);
        int cc = 0;
        vector<int> vis(isConnected.size(), 0);
        for(int i = 0; i < isConnected.size(); i++){
            if(vis[i] == 0){
                dfs(g, i, vis);
                cc++;
            }
        }
        return cc;
    }
};