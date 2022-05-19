// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int power(int x, int n){
	    if(n == 0)
	        return 1;
        int m = power(x, n/2);
        if((n&1) == 1) return x*m*m;
        else return m*m;
	}
	int NthRoot(int n, int m)
	{
	    for(int i = 1; i <= 30; i++){
	        int temp = power(i,n);
	        if(temp == m){
	            return i;
	        }
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends