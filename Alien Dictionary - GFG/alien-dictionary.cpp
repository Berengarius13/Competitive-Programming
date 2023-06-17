//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void topSort (unordered_map<char, vector<int>> &g, char node, stack<char> &stk, unordered_map<char,int> &vis){
        vis[node] = true;
        
        for(auto cnode : g[node]){
            if(vis[cnode] == false){
                topSort(g, cnode, stk, vis);
            }
        }
        stk.push(node);
    }
    
    string findOrder(string dict[], int n, int k) {
        unordered_map<char, vector<int>> g;
        for(char ch = 'a'; ch < ('a' + k); ch++){
            g[ch];
        }
        string s;
        char node = 'a';
        node = dict[0][0];
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < min(dict[i].size(), dict[i+1].size()); j++){
                if(dict[i][j] != dict[i+1][j]){
                    g[dict[i][j]].push_back(dict[i+1][j]);
                    // if(i == 0){
                    //     node = dict[i][j];
                    // }
                    break;
                }
            }
        }
        // run top sort;
        stack <char> stk;
        unordered_map<char, int> vis;
        for(char ch = 'a'; ch < 'a' + k; ch++){
            vis[ch] = false;
        }
        for(char ch = 'a'; ch < 'a' + k; ch++){
            if(vis[ch] == false){
                topSort(g, ch, stk, vis);
            }
        }
        while(!stk.empty()){
            s.push_back(stk.top());
            stk.pop();
        }
        // cout << s << " ";
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends