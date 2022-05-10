class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &num : nums){
            m[num]++;
        }
        int ans;
        for(auto &it : m){
            if(it.second> (nums.size()/2))
            {
                ans = it.first;
            }
        }
        return ans;
    }
};