class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sor = nums;
        std::sort(sor.begin(), sor.end());
        vector<int> ans;
        int s = 0;
        int e = sor.size()-1;
        while (s<=e){
            int m=(e+1+s)/2;
                if (sor[e]+sor[s]>target){
                    e--;
                }
                else if (sor[e]+sor[s]<target){
                    s++;
                }
                else {
                    
                    break;
                }
        }
        for (int i=0; i<nums.size(); i++){
            if(sor[s]==nums[i]){
                ans.push_back(i);}
            else if (sor[e]==nums[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    
};
// USE TWO POINTER METHOD FOR THIS ONE;