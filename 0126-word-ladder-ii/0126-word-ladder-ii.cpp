#define graph unordered_map<int, vector<int>> 
// Debug Template, copied from Mikel_Arteta_8 (https://codeforces.com/blog/entry/68809)
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


class Solution {
public:
    void find_path(vector<vector<int>> &parent, int node, vector<int> &path,                         vector<vector<int>> &paths)
    {
        if(node == -1){
            paths.push_back(path);
            return;
        }
        
        for(auto &cnode : parent[node]){
            path.push_back(node);
            find_path(parent, cnode, path, paths);
            path.pop_back();
        }
        
    }
    
    vector<vector<string>> findLadders(string begin, string end, vector<string>& words) {
        graph g;
        map<string, int> mp;
        vector<vector<string>> ans;
        int n = words.size();
        int dest = -1;
        for(int i = 0; i < n; i++){
            mp[words[i]] = i;
            if(words[i] == end) dest = i;
        }
        if(dest == -1) return ans;
        mp.insert({begin, n});
        for(int j = 0; j <= n; j++){
            string word = (j == n)? begin : words[j];
            for(int i = 0; i < word.size(); i++){
                char store = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(ch != store){
                        word[i] = ch;
                        if(mp.find(word) != mp.end()){
                            g[j].push_back(mp[word]);
                        }
                    }
                }
                word[i] = store;
            }
        }
        vector<vector<int>> parent(n+2);
        vector<int> dist(n+2, INT_MAX);
        parent[n].push_back(-1);
        dist[n] = 0;
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto cnode : g[node]){
                if(dist[cnode] > dist[node] + 1){
                    dist[cnode] = dist[node] + 1;
                    q.push(cnode);
                    parent[cnode].clear();
                    parent[cnode].push_back(node);
                }
                else if(dist[cnode] == dist[node] + 1){
                    // no need to add cnode again as it already exist in queue
                    parent[cnode].push_back(node);
                }
            }
        }
        // debug(parent);
        vector<vector<int>> paths;
        vector<int> path;
        find_path(parent, dest, path, paths);
        for(auto &it : paths){
            reverse(it.begin(), it.end());
            vector<string> st;
            for(auto &id : it){
                string word = (id == n)? begin : words[id];
                st.push_back(word);
            }
            ans.push_back(st);
        }
        return ans;
    }
};