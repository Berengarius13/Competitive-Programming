class Solution {
public:
    bool isPossible(vector<int> &nums, int val, int k){
        int splits = 1;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > val) return false;
            if(nums[i] + cur_sum > val){
                cur_sum = 0;
                splits++;
            }
            cur_sum += nums[i];
        }
        if(cur_sum > val) splits++;
        return splits <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        int e = 1e9;
        while(s <= e){
            int mid = 1ll * (s+e)/2;
            if(isPossible(nums, mid, k)){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        // cout << isPossible(nums, 14, k);
        // int cur_sum = 0;
        // int val = e;
        // int mx = INT_MIN;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] + cur_sum > val){
        //         cur_sum = 0;
        //     }
        //     cur_sum += nums[i];
        //     mx = max(cur_sum, mx);
        // }
        return s;
    }
};