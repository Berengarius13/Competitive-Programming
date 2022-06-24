// Return bridge edges
class Solution {
public:
    typedef vector<vector<int>> graph;
    vector<vector<int>> ans;
    graph make_graph(vector<vector<int>>& edges, int n){
        graph g (n);
        for(auto &it : edges){
            int u = it[0];  int v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }
    int time = 0;
    void dfs(graph &g, int node, int parent, vector<int> &disc, vector<int> &low){
        disc[node] = low[node] = ++time;
        
        for(auto &cnode : g[node]){
            if(parent == cnode) continue;
            if(disc[cnode] != -1){
                low[node] = min(low[node], disc[cnode]);
            }
            else{
                dfs(g, cnode, node, disc, low);
                low[node] = min(low[node], low[cnode]);
                if(low[cnode] > disc[node])
                    ans.push_back(vector<int> {cnode, node});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        graph g = make_graph(connections, n);
        for(int i = 0; i < n; i++){
            if(disc[i] == -1)
                dfs(g, i, -1, disc, low);
        }
        return ans;
    }
};