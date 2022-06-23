// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    vector<vector<int>> ans;
    int time = 0;
    void dfs(vector<int> adj[], int node, vector<int> &disc, vector<int> &low, vector<bool> &stkItem, stack<int> &stk){
        disc[node] = low[node] = ++time;
        stk.push(node);
        stkItem[node] = true;
        
        for(auto &cnode : adj[node]){
            if(disc[cnode] == -1){
                dfs(adj, cnode, disc, low, stkItem, stk);
                low[node] = min(low[cnode], low[node]);
            }
            else if(stkItem[cnode] == true){
                low[node] = min(low[node], disc[cnode]);
            }
        }
        
        int popped = 0;
        
        if(low[node] == disc[node]){ // Condition for root node of SSC
            vector<int> temp;
            while(stk.top() != node){
                popped = stk.top(); stk.pop();
                temp.push_back(popped);
                stkItem[popped] = false;
            }
            temp.push_back(stk.top());
            stk.pop();
            stkItem[node] = false;
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<bool> stkItem(V, false); // Remember which item is in stack
        vector<int> disc (V, -1); // Remember time at which it was interted
        vector<int> low (V, -1); // Remember the low value
        stack<int> stk; // Nodes in particular ssc in stack
        for(int i = 0; i < V; i++){
            if(disc[i] == -1)
                dfs(adj, i, disc, low, stkItem, stk);
        }
        sort(ans.begin(), ans.end());
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends