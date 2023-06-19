#define graph unordered_map<int, vector<int>> 
class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        graph g;
        map<string, int> mp;
        int n = words.size();
        for(int i = 0; i < n; i++){
            mp[words[i]] = i;
        }
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
        // do bfs
        int ans = 1;
        queue<int> q;
        q.push(n);
        vector<int> vis(n+2, 0);
        vis[n] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                string cur = (node == n)?begin : words[node];
                if(cur == end){
                    return ans;
                }
                for(auto &cnode : g[node]){
                    if(vis[cnode] == false){
                        vis[cnode] = true;
                        q.push(cnode);
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};