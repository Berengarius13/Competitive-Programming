/* *
 * '|' is break point.
 * |1234
        -> 1|234
                -> 12|34
                        -> 123|4
                        -> 124|3
                -> 13|24
                        -> 132|4
                        -> 134|2
                -> 14|23
                        -> 142|3
                        -> 143|2
        -> 2|134
                >> so on....
 */
/* *
 * Making ovservation on above solution tree
 * Lets assume => i | array
 * If left of breakpoint aka i, is greatest
   aka greater than last value, then we need to "step back"
 * We will keep stepping back until we can step ahead
   aka, we will swap i with it's just greater value
 * Make simple observation that next of i is always sorted
   if not than swap i with it's just greater value
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--){
            // If maximum value is greater than i value
            // Sort it with remaining value, aka put it in end
            // Cuz it is already sorted
            if(nums[i] >= nums[nums.size()-1]){
                for(int j = i+1; j < nums.size(); j++)
                    swap(nums[j], nums[j-1]); // this will sort
            }
            // Swap the i value with just greater value
            else{
                for(int j = i+1; j < nums.size(); j++)
                    if(nums[j] > nums[i]){
                        swap(nums[j], nums[i]);
                        return;
                }
            }
        }
    } 
};