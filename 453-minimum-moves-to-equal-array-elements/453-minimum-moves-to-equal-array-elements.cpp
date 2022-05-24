class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto &num:nums)
            mini = min(mini, num);
        int sum = 0;
        for(auto &num:nums)
            sum += num-mini;
        return sum;
    }
};