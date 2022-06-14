// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    /*
     * If relaxation possible at n th time negative cycle
     */
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, 1e8);
	    
	    dist[0] = 0;
	    for(int i = 0; i < n-1; i++){
	        for(int E = 0; E < edges.size(); E++){
	            int u = edges[E][0];
	            int v = edges[E][1];
	            int w = edges[E][2];
	            
	            if(dist[u]+w < dist[v]){
	                dist[v] = dist[u] + w;
	            }
	        }
	    }
	    int fl = 0;
	    for(int E = 0; E < edges.size(); E++ ){
	            int u = edges[E][0];
	            int v = edges[E][1];
	            int w = edges[E][2];
	            
	            if(dist[u]+w < dist[v]){
	                fl = 1;
	           }
	    }
	    return fl;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends