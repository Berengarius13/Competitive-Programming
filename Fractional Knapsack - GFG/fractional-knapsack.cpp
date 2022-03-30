// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        multimap<double, int > m;
        for(int i = 0; i < n; i++){
            m.insert(make_pair((double)arr[i].weight/arr[i].value, i));
        }
        double profit = 0.0; 
        double sum = 0.0;
        for(auto &it : m){
             
            if(sum +arr[it.second].weight <= W){
                sum = sum+arr[it.second].weight;
                profit = profit + arr[it.second].value;
            }
            else {
                double rem = W-sum;
                double fraction = (double)rem/arr[it.second].weight;
                profit = profit + fraction*arr[it.second].value;
                break;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends