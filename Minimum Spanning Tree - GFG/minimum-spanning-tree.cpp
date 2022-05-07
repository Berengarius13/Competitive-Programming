// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> key(V, INT_MAX); // To track value, there can be only one parent of node n, 
                        // that parent must be minimum, we keep track what value connects 
                        // to that node n
        vector<int> mst(V, 0); // To to check if node is in MST or not
        key[0] = 0; // As 0 have no parent
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            mst[node] = 1;
            for(auto &cnode : adj[node]){
                int weight = cnode[1];
                int child_node = cnode[0];
                if(mst[child_node] == 0 && weight < key[child_node]){
                    key[child_node] = weight;
                    pq.push({weight, child_node});
                }
            }
        }
        int sum = 0;
        for(auto &su : key){
            sum += su;
        }
        return sum;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends