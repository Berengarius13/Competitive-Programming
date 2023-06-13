class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int l = 0, r = 0;
        int ans = INT_MAX;
        while(l <= r && r < n){
            
            while(r < n && sum < target){
                sum += nums[r];
                r++;
            }
            cout << sum <<" ";
            // sum += nums[r];
            while(sum >= target && l <= r){
                ans = min(ans, r - l );
                sum -= nums[l];
                // cout << sum << " ";
                l++;
                // cout << endl;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};