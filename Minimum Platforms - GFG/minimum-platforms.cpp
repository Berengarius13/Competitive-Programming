// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Here we have to sort both arrival and departure
    // Until first tra
    int findPlatform(int arr[], int dep[], int n)
    {   
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int ans=0;
        int count=0;
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j]) //one more platform needed
            {
                count++;
                i++;
            }
            else //one platform can be reduced
            {
                count--;
                j++;
            }
            ans=max(ans,count); //updating the value with the current maximum
        }
    return ans;
    }
    
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends