class Solution {
public:
    // either cookie goes to first/ second/ third bag
    void fun(vector<int> &nums, int i, vector<int> &bag, int &mn){
        int n = nums.size();
        // calculate unfairness
        if(i == n){
            int mx = INT_MIN;
            for(auto &num : bag){
                mx = max(num, mx);
            }
            mn = min(mn, mx);
            return;
        }
        
        for(int j = 0; j < bag.size(); j++){
            bag[j] += nums[i];
            fun(nums, i+1, bag, mn);
            bag[j] -= nums[i];
        }
    }
    int distributeCookies(vector<int>& nums, int k) {
        vector<int> bag(k, 0);
        int mn = INT_MAX;
        fun(nums, 0, bag, mn);
        return mn;
    }
};