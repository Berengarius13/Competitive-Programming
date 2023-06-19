class Solution {
public:
    bool check(vector<int> &nums){
        bool flag = true;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) flag = false;
        }
        return flag;
    }
    bool checkPossibility(vector<int>& nums) {
        bool flag = check(nums);
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                int a = nums[i];
                int b = nums[i+1];
                nums[i] = nums[i+1] = a;
                flag |= check(nums);
                nums[i] = nums[i+1] = b;
                flag |= check(nums);
                break;
            }
            
        }
        return flag;
    }
};