// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int kam = INT_MAX;
    int knapsack(int arr[], int n,int total ,int i, int sum, vector<vector<int>> &memo){
        if(memo[i][sum] != -1) return memo[i][sum];
        if(i == n){
            //cout<<sum<<" ";
            int k = (2*sum) - total;
            return abs(k);
        }
        
        int a = knapsack(arr, n, total, i+1, sum+arr[i], memo);
        int b = knapsack(arr, n, total, i+1, sum, memo);
        
        memo[i][sum] = min(a,b);
        return min(a, b);
    }
	int minDifference(int arr[], int n)  { 
	    int total = 0;
	    for(int i = 0; i < n; i++)
	        total += arr[i];
        vector<vector<int>> memo(n+2, vector<int> (total+2, -1));
	    return knapsack(arr, n, total ,0, 0, memo);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends