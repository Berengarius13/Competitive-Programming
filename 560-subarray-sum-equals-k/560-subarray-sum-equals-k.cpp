class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix; // Calculate prefix sum
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix.push_back(sum);
            sum += nums[i];
        }
        prefix.push_back(sum);
        unordered_map<int, int> mp; // sum -> index
        int count = 0;
        for(int i = 0; i < prefix.size(); i++){
            int a = prefix[i];
            int b = a - k;
            count += mp[b];
            mp[a]++;
        }
        return count;
    }
};