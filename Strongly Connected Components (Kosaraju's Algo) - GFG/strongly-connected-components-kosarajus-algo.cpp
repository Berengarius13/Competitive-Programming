// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	typedef vector<vector<int>> graph;
	stack<int> top_sort;
	void dfs(vector<int> adj[], int node ,vector<int> &vis){
	    vis[node] = 1;
	    
	    for(auto &cnode : adj[node])
	        if(vis[cnode] == 0)
	            dfs(adj, cnode, vis);
        
        top_sort.push(node);
	}
	graph make_transpose_graph(vector<int> adj[], int V){
	    graph g(V);
	    for(int node = 0; node < V; node++){
	        for(auto &cnode : adj[node]){
	            g[cnode].push_back(node);
	        }
	    }
	    return g;
	}
	void dfs_trans(graph &g, int node, vector<int> &vis){
	    vis[node] = 2;
	    for(auto &cnode : g[node])
	        if(vis[cnode] == 1)
	            dfs_trans(g, cnode, vis);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        for(int i = 0; i < V; i++){
            if(vis[i] == 0)
                dfs(adj, i, vis);
        }
        graph trans_g = make_transpose_graph(adj, V);
        int ans = 0;
        while(!top_sort.empty()){
            int top_node = top_sort.top();
            top_sort.pop();
            if(vis[top_node] == 1){
                dfs_trans(trans_g, top_node, vis);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends