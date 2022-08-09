/* How?
* Correct  approch would be to think 2 people starting from 
top at the same time, 1 and 2 with coordinates r1, r2, c1, c2
* The combined sum of cherries picked up by them should be maximum
* *** The manhatten distance of both points from orign should be same
aka they should move one step at a time
  r1 + c1 = r2 + c2
  This way we don't need to use 4d DP
* If they are at same point just count one value only 
* 4 Cases -> & -> || ^ & -> || ^ & ^ || -> & ^
*/
class Solution {
public:
    int dp[51][51][51];
    int func(int r1 , int c1 , int r2 , int n , vector<vector<int>> &grid )
    {
        int c2=r1+c1-r2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2]!=-1)
        {
            return dp[r1][c1][r2];
        }
        
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        
        int ans=grid[r1][c1];
        
        if(r1!=r2)
        {
            ans += grid[r2][c2];
        }
        
        int temp= max(func(r1+1 , c1 , r2+1 , n , grid) , func(r1 , c1+1 , r2 , n , grid));
        temp = max(temp , func(r1+1 , c1 , r2 , n, grid));
        temp = max(temp , func(r1 , c1+1 , r2+1 , n , grid));
        
        ans+=temp;
        
        return dp[r1][c1][r2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        int n=grid.size();
        return max(0 , func(0,0,0,n , grid));
    }
};