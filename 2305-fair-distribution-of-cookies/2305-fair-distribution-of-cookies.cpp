/* *
 * DFS tree will have K nodes
 * All representing k way to fill the continer
 * DFS to get all possible subsets such that they need
   to be divided in three parts 
   --  --  --
   -   --- ----
   ---- - ---
   All possible subset possibilities
 */
class Solution {
public:
    int ans = INT_MAX;
    
    void dfs(vector<int>& nums, int i, int &k, vector<int> &container){
        if(i == nums.size()){
            int mx = INT_MIN;
            for(auto &it : container)
                mx = max(mx, it);
            
            ans = min(mx, ans);
            return;
        }
        
        for(int p = 0; p < k; p++){
            container[p] += nums[i];
            dfs(nums, i+1, k, container);
            container[p] -= nums[i];
        }
         
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> container(k, 0);
        dfs(cookies, 0,k, container);
        return ans;
    }
};