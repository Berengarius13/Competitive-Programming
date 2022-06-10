// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int M = 1000000007;
	int knapsack(int arr[], int n, int total ,int i, int sum, vector<vector<int>> &memo){
        if(memo[i][sum] != -1) return memo[i][sum];
        if(i == n){
            if(sum == total) return 1;
            else return 0;
        }
        
        int a = (knapsack(arr, n, total, i+1, sum+arr[i], memo))%M;
        int b = (knapsack(arr, n, total, i+1, sum, memo))%M;
        
        memo[i][sum] = (a+b)%M;
        return (a+b)%M;
    }
	int perfectSum(int arr[], int n, int summ)
	{
	    int totall = 0;
	    for(int i = 0; i < n; i++)
	        totall += arr[i];
        vector<vector<int>> memo(n+2, vector<int> (totall+2, -1));
	    return knapsack(arr, n, summ ,0, 0, memo);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends