/* *
 * Keep track of min and max at every iteration
 * If mn - mx exceed k, that means there exist a subsequence
   with we missed before which satisfies our condition thus
   we incriment it later
 */
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = nums[0];
        int mx = nums[0];
        int count = 1; // Because we are counting when we are at next case
        for(int i = 0; i < nums.size(); i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
            if((mx-mn) > k){
                count++;
                mn = mx = nums[i];
            }
        }
        return count;
    }
};