// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{   // STEP 1
    public:
    int knapsack(int wt[], int val[], int weight_left, int i, int n, vector<vector<int>> &memo){
        if(memo[i][weight_left] != -1) return memo[i][weight_left];
        if(i >= n || weight_left <= 0)  return 0;
        int profit1 = 0;
        if( wt[i] <= weight_left){
            profit1 = val[i] + knapsack(wt, val, weight_left- wt[i], i+1, n, memo);
        }
        int profit2 = knapsack(wt, val, weight_left, i+1, n, memo);
        
        memo[i][weight_left] = max(profit1, profit2);
        return max(profit1, profit2);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> memo(n+2, vector<int> (W+2, -1));
        return knapsack(wt, val, W, 0, n, memo);
        
    }
};





































/*
Subset solution
public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    // Function to get sum of all values in vector
    int sum_of_vec(vector<int> temp){
        int sum = 0;
        for(auto &it : temp)
            sum += it;
        return sum;
    }
    int max_sum = 0;
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
            m.insert({wt[i], val[i]});
        vector<vector<int>> sub;
        sub = {{}};
        for(int i = 0; i < n; i++){
            int si = sub.size();
            for(int j = 0; j < si; j++){
                sub.push_back(sub[j]); 
                sub.back().push_back(wt[i]);
            }
        }
        for(auto &wts: sub){
            int sum = 0;
            int weight = sum_of_vec(wts);
            if(weight <= W){
                for(auto &p : wts)
                    sum += m[p];
            }
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
*/

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends