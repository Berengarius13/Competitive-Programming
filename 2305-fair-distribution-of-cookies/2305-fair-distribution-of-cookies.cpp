class Solution {
public:
    int ans = INT_MAX;
    void dfs(vector<int> &nums, int i, vector<int> &container){
        if(i == nums.size()){
            int maxi = INT_MIN;
            for(auto &it : container){
                maxi = max(maxi, it);
            }
            ans = min(ans, maxi);
            return;
        }
        
        for(int k = 0; k < container.size(); k++){
            container[k] += nums[i];
            dfs(nums, i+1, container);
            container[k] -= nums[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> container(k, 0);
        dfs(cookies, 0, container);
        return ans;
    }
};