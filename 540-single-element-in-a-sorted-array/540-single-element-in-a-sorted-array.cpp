/* * 
 * RIGHT HALF
       First Instance => Odd index
       Second Instace => even index
 * LEFT HALF
       First Instance => even index
       Second Instace => odd index
 * Write cases down that's the observation you make
 * We want break point (that is high < low) when low 
   is at the non repeated element
 * That break line should be on left on non 
    repeated element
 * Note on xor, 
   even xor 1, gives next odd element.
   odd xor  1, gives previous even element.
 * If([x] == [x^1]) gives us 4 comparisons
      when x is even:
        x == x + 1
      when x is odd
        x == x - 1;       
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2; // For case when ans is last element
        while(high >= low){
            int mid = (low+high)>>1;
            if(nums[mid] == nums[mid^1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};

/*
 * My method is to go to the middle and divide into 2 subarray
 * We know for sure that extra element will be on subarray that is odd
 * So throw even one out and put s on first element of odd array
 * And also check if middle one is our answer or not, 2 cases
 * We want middle one to be at first instance of it's repetition
 * Check start and end every time
 */

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int s = 0;
//         int e =  nums.size()-2;
//         while(e>s){
//             if(nums[s] != nums[s+1])
//                 return nums[s];
//             if(nums[e] != nums[e+1])
//                 return nums[e+1];
//             int m = (s+e)/2;
//             if(nums[m] == nums[m-1]) m--;
//             if(nums[m] == nums[m+1]){
//                 if(((m-s)&1) == 1)
//                     e = m-2;
//                 else
//                     s = m+2;
//             }
//             else{
//                 if(((m-s)&1) == 1)
//                     return nums[m+1];
//                 else
//                     return nums[m];
//             }
//         }
//         return nums[0];
//     }
// };