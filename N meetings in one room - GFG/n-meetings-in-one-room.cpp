// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{   
    // Sort in terms of ending time
    // Check if next start is greater than previso end
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        multimap<int, pair<int,int>> mp;
        for(int i= 0; i < n; i++){
            mp.insert({end[i], make_pair(start[i], i)});
        }
        int next_start  = -1;
        int count = 0;
        for(auto &it : mp){
            if(it.second.first > next_start){
                next_start = it.first;
                count++;
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends