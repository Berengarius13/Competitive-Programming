class Solution {
public:
    int sum_of_ap(int n){
        if((n&1) == 1){
            return ((n+1)/2)*n;
        }
        else{
            return (n/2)*(n+1);
        }
    }
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto &num:nums){
            sum+= num;
        }
        return sum_of_ap(n)-sum;
    }
};