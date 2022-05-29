// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        vector<int> prime (N+1, 1);
        vector<int> hp (N+1, 0);
        prime[1] = 0; prime[0] = 0;
        hp[1] = 1;
        for(int i = 2; i <=N; i++){
            if(prime[i] == 1){
                hp[i] = i;// If a number is prime it's lowest pf, is itself
                for(int j = 2*i; j <= N; j += i){
                    prime[j] = 0; // It's not a prime after that  
                    hp[j] = i;
                }
            }
        }
        return (long long int)hp[N];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends