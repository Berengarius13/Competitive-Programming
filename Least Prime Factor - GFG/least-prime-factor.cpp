// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> prime (n+1, 1);
        vector<int> lp (n+1, 0);
        prime[1] = 0; prime[0] = 0;
        lp[1] = 1;
        for(int i = 2; i <=n; i++){
            if(prime[i] == 1){
                lp[i] = i;      // If a number is prime it's lowest pf, is itself
                for(int j = 2*i; j <= n; j += i){
                    prime[j] = 0; // It's not a prime after that  
                    if(lp[j] == 0){
                        lp[j] = i; // Mark the first prime factor that comes to cut it
                    }
                }
            }
        }
        return lp;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}
  // } Driver Code Ends