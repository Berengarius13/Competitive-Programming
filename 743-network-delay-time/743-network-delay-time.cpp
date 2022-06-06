/* Dijkstras Shortest Path algorithm*/
class Solution {
public:
    typedef vector<vector<pair<int, int>>> graph;
    graph make_graph(vector<vector<int>>& times, int n){
        graph g (n+1);
        for(auto &it: times){
            int source = it[0];
            int target = it[1];
            int weight = it[2];
            g[source].push_back(make_pair(target, weight));
        }
        return g;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> path (n+1, INT_MAX);
        graph g = make_graph(times, n);
        if(g[k].size() == 0) return -1;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        path[k] = 0;
        pq.push({path[k], k});
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            for(auto &it : g[node]){
                int cnode = it.first;
                int weight_to_cnode = it.second;
                if(path[cnode] > weight_to_cnode + path[node]){
                    path[cnode] = weight_to_cnode + path[node];
                    pq.push({path[cnode], cnode});
                }
            }
        }
        int mx = 0;
        for(int j = 1; j < n+1; j++){
            mx = max(mx, path[j]);
        }
        if(mx == INT_MAX) return -1;
        else return mx;
        
    }
};