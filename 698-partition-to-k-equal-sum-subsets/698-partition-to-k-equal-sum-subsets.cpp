class Solution {
public:
    bool dfs(vector<int> &nums, int i, int &side, vector<int> &container){
        if(i == nums.size()) return true;
        
        for(int p = 0; p < container.size(); p++){
            container[p] += nums[i];
            if((p == 0 || container[p-1] != 0) && container[p] <= side)
                if(dfs(nums, i+1, side, container)) 
                    return true;
            container[p] -= nums[i];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() < k) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        sum = sum/k;
        vector<int> container(k, 0);
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, 0, sum, container);
    }
};