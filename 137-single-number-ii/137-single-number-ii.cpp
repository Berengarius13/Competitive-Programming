/*
* Use bit manupulation
0001
0001
0001
0010
0010
0010
0101
____
0134
If a number appears 3 times their set bits will also appears 3 times
* Remember that to represent an answer we just need to remember the 
set bits and thier position
* So if total set bit count of a single column % 3 != 0 we have a set 
bit from non repeating element their 
* Use that information
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(auto num : nums)
                if((num & (1 << i))) count++;
            
            if(count % 3 != 0) ans = ans | (1<<i);
        }
        return ans;
    }
};