class Solution {
public:
    int minStartValue(vector<int>& nums) {
       int sum = 0;
       int mn = INT_MAX;
       for(auto num : nums){
           sum += num;
           mn = min(mn, sum);
       }
        cout<< mn;
       if(mn >= 1) return 1;
       return abs(mn) + 1;
    }
};