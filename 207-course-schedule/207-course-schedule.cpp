/*
// Cannot run DFS directly as we first need to convert it to adjancy list
void dfs(vector<vector<int>> &pre, int p, vector<int> &vis)
    {
        vis[p] = 1;
        for(auto &node: pre[p]){
            if(vis[node] == 0)
            dfs(pre, node, vis);
        }
        return;
    }
*/
// Without backtracking we will solve like this 
class Solution {
public:
    bool ans = true;
    typedef vector<vector<int>> graph;
    void dfs(vector<vector<int>> &pre, int p, vector<int> &vis, vector<int> par)
    {
        if(!ans) return;
        vis[p] = 1;
        par[p] = 1;
        for(auto &node: pre[p]){
            if(vis[node] == 0)
            dfs(pre, node, vis, par);
            else{
                if(par[node]==1){
                    ans = false;
                    return;
                }
            }
        }
        
        return;
    }
    // First we will create adjacncy list
    graph make_graph(int &num, graph &pre){
        graph g(num);
        for(auto &it: pre){
            g[it[0]].push_back(it[1]);
        }
        return g;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = make_graph(numCourses, prerequisites);
        vector<int> vis(numCourses, 0);
        vector<int> par(numCourses, 0);
        for(int i = 0; i<numCourses; i++)
            dfs(g, i, vis, par);
               
        return ans;
    }
    
};

/*
class Solution {
public:
    bool ans = true;
    typedef vector<vector<int>> graph;
    void dfs(vector<vector<int>> &pre, int p, vector<int> &vis, vector<int> &par)
    {
        vis[p] = 1;
        par[p] = 1;
        for(auto &node: pre[p]){
            if(vis[node] == 0)
            dfs(pre, node, vis, par);
            else{
                if(par[node]==1){
                    ans = false;
                    return;
                }
            }
        }
        par[p] = 0;
        return;
    }
    // First we will create adjacncy list
    graph make_graph(int &num, graph &pre){
        graph g(num);
        for(auto &it: pre){
            g[it[0]].push_back(it[1]);
        }
        return g;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = make_graph(numCourses, prerequisites);
        vector<int> vis(numCourses, 0);
        vector<int> par(numCourses, 0);
        for(int i = 0; i<numCourses; i++)
            dfs(g, i, vis, par);
               
        return ans;
    }
    
};
*/
