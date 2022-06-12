// Longest substring without repeat
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_map<int,int> mp;
        int max_sum= 0;
        int start = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(mp.find(nums[i]) != mp.end()){
                int index = mp[nums[i]];
                for(int k = start; k <= index; k++){
                    mp.erase(nums[k]);
                    sum -= nums[k];
                }
                start = index+1; //sum = nums[index+1];
            }
            sum += nums[i];
            mp.insert({nums[i], i}); // a => 0, b=>1, c=>2, 
            max_sum = max(max_sum, sum);
        }
        return max_sum;
     
    }
};