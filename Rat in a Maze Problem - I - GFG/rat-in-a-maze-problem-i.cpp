// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void rat(vector<vector<int>> &m, int i, int j, string str){
        if(i == m.size()-1 && j==m.size()-1){
            ans.push_back(str);
            return;
        }
        if(m[0][0]==0) return;
        if(i-1 >= 0 && m[i-1][j] == 1){
            m[i-1][j] = 0;
            str.push_back('U');
            rat(m, i-1, j, str);
            str.pop_back();
            m[i-1][j] = 1;
        }
        if(j-1>= 0 && m[i][j-1] == 1){
            m[i][j-1] = 0;
            str.push_back('L');
            rat(m, i, j-1, str);
            str.pop_back();
            m[i][j-1] = 1;
        }
        if(j+1 < m.size() && m[i][j+1] == 1){
            m[i][j+1] = 0;
            str.push_back('R');
            rat(m, i, j+1, str);
            str.pop_back();
            m[i][j+1] = 1;
        }
        if(i+1 < m.size() && m[i+1][j] == 1){
            m[i+1][j] = 0;
            str.push_back('D');
            rat(m, i+1, j, str);
            str.pop_back();
            m[i+1][j] = 1;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string str;
        rat(m, 0, 0, str);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends