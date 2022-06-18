class Solution {
public:
    typedef vector<vector<int>> graph;
    graph make_graph(int &num, graph &pre){
        graph g(num);
        for(auto &it: pre){
            g[it[1]].push_back(it[0]);
        }
        return g;
    }
    stack<int> stk;
    bool dfs(graph &g, int node, vector<int> &vis, vector<int> &par){
        vis[node] = 1;
        par[node] = 1;
        for(auto &cnode : g[node]){
            if(vis[cnode] == 0){
                if(dfs(g, cnode, vis, par)) return true;
            }
            else if(par[cnode] == 1){
                return true;
            }
            
        }
        par[node] = 0;
        stk.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = make_graph(numCourses, prerequisites);
        vector<int> vis(g.size(), 0);
        vector<int> par(numCourses, 0);
        vector<int> ans;
        for(int i = 0; i < g.size(); i++){
            if(vis[i] == 0)
                if(dfs(g, i, vis, par))return ans;
        }
        while(!stk.empty()){
            ans.push_back(stk.top()); stk.pop();
        }
        return ans;
    }
};