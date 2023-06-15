//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool dfs(int node, vector<int> &safe, vector<bool> &vis, vector<int> adj[]){
        vis[node] = true;
        if(adj[node].size() == 0){
            safe[node] = true;
            return true;
        }
        bool val = true;
        for(auto cnode : adj[node]){
            if(vis[cnode] == false){
                val &= dfs(cnode, safe, vis, adj);
                
            }
            else if(safe[cnode] == false){
                val = false;
            }
        }
        if(val == true){
            safe[node] = true;
            // val = false;
        }
        return val;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> safe(V+1, false);
        vector<bool> vis(V+1, 0);
        for(int i = 0; i < V; i++){
            if(vis[i] == false) dfs(i, safe, vis, adj);
        }
        vector<int> ans;
        for(int i = 0; i < V+1; i++){
            if(safe[i] == true) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends