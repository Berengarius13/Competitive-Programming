class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;
        int m = 0;
        int e = nums.size() -1;
        while(m <=e){
            if(nums[m] == 1)
                m++;
            else if (nums[m] == 2){
                swap(nums[m], nums[e]);
                e--;
            }
            else {
                swap(nums[m], nums[s]);
                s++;
                m++;
            }
        }
    }

};
    
/* 
* Two Pass Method
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0; 
        int e = nums.size() -1;
        // Bring all 2's to the end
        while(s<=e){
            if(nums[s] == 2){
                swap(nums[s], nums[e]);
                e--;
            }
            else
                s++;
        }
        // Bring all 1's to the end
        s = 0;
        while(s<=e){
            if(nums[s] == 1){
                swap(nums[s], nums[e]);
                e--;
            }
            else
                s++;
        }
        
    }
};
*/