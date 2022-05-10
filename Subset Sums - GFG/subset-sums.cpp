// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<vector<int>> subs{{}};
        vector<int> sum;
        for(auto &num : arr){
            int n = subs.size();
            for(int i = 0; i < n; i++){
                
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        for(auto &s:subs){
            sum.push_back(accumulate(s.begin(), s.end(), 0));
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends