// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Remember each node have only one parent
// You remember there exist a way to reach node n, in key
// You update key if there exist a better way to reach node
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //optimal sol O(NlogN)
        
        // int par[V];
        int key[V];
        bool mst[V];
        
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX,mst[i]=false;
        }
        
        key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({key[0],0});  //key[],weight
        
        while(!pq.empty())
        {
            int u=pq.top().second;   //edge u-->v
            pq.pop();
            
            mst[u]=true;
            for(auto it:adj[u])
            {
                int v=it[0];
                int wt=it[1];
                
                if(mst[v]==false and wt<key[v])
                {
                    key[v]=wt;
                    pq.push({key[v],v});
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=key[i];
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