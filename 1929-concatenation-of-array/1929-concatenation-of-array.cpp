class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans; 
        for(auto &num: nums)
            ans.push_back(num);
        for(auto &num: nums)
            ans.push_back(num);
        return ans;
    }
};