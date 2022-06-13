// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapsack(int N, int W, int val[], int wt[], int i,vector<vector<int>> &memo ){
        if(memo[i][W] != -1) return memo[i][W];
        if(i == N || W <= 0) return 0;
        int profit1 = 0;
        if(wt[i] <= W){
            profit1 = val[i] + knapsack(N, W-wt[i], val, wt, i, memo);
        }
        int profit2 = knapsack(N, W, val, wt, i+1, memo);
        
        memo[i][W] = max(profit1, profit2);
        return max(profit1, profit2);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> memo(N+2, vector<int> (W+2, -1));
        return knapsack(N, W, val, wt, 0, memo);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends