#define graph unordered_map<int, vector<int>>
#define ll long long
class Solution {
public:
    bool isIntersecting(vector<int> a, vector<int> b){
        ll x1 = a[0]; ll y1 = a[1]; ll r1 = a[2];
        ll x2 = b[0]; ll y2 = b[1]; ll r2 = b[2];    
        ll d1 = (x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2);
        if(d1 <= r1*r1) return true;
        return false;
    }
    int dfs(graph &g, int node, unordered_set<int> &vis){
        vis.insert(node);
        for(auto cnode : g[node]){
            if(vis.find(cnode) == vis.end()){
                dfs(g, cnode, vis);
            }
        }
        return vis.size();
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        graph g;
        for(int i = 0; i < bombs.size(); i++){
            for(int j = 0; j < bombs.size(); j++){
                if(i != j && isIntersecting(bombs[i], bombs[j])){
                    g[i].push_back(j);
                }
            }
        }
        int mx = INT_MIN;
        for(int i = 0; i < bombs.size(); i++){
            unordered_set<int> vis;
            mx = max(dfs(g, i, vis),mx);
        }
        return mx;
    }
};