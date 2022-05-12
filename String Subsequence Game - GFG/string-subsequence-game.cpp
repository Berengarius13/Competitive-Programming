// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    set<string> allPossibleSubsequences(string S) {
        // code here
        set<string> ans;
        for(int k = 0; k < (1 << S.size()); k++){
            string temp;
            for(int i = 0; i < S.size(); i++){
                if((k & (1 << i)) != 0)
                    temp.push_back(S[i]);
            }
            char s = *temp.begin();
            char e = *(--temp.end());
            if((s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')&& (e != 'a' && e != 'e' && e != 'i' && e != 'o' && e != 'u'))
                ans.insert(temp);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
  // } Driver Code Ends