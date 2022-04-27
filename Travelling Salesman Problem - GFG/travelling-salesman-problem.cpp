// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
typedef vector<vector<vector<int>>> graph;
int kost = 100000;
graph make_graph(vector<vector<int>> cost){
    graph g (cost.size());
    for(int i = 0; i < cost.size(); i++){
        for(int j = 0; j < cost.size() ; j++){
            if(i == j) continue; 
            vector<int> temp = {j , cost[i][j]};
            g[i].push_back(temp);
        }
    }
    return g;
}
void dfs(graph &g, vector<int> vis, int node, int p, int cst){
    vis[node] = 1;
    int n = vis.size();
    
    for(auto &cnode: g[node]){
        if(vis[cnode[0]] == 0){
            cst += cnode[1];
            dfs(g, vis, cnode[0], p+1, cst);
            cst -= cnode[1];
        }
        else if(p == n && cnode[0] == 0){
            cst += cnode[1];
            kost = min(kost, cst);
            return;
        }
    }
    
}
int total_cost(vector<vector<int>>cost){
    int n = cost.size();
    if(n==1) return 0;
    graph g;
    g = make_graph(cost);
    vector<int> vis(g.size(), 0);
    dfs(g, vis, 0, 1, 0);
    return kost;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends