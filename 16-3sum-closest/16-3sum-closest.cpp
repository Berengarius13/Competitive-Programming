class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2]; 
        for(int i = 0; i < nums.size(); i++){
            if((i > 0) && (nums[i] == nums[i-1])) 
                continue;
            int a = nums[i];
            int front = i+1; int back = nums.size()-1;
            while(front < back){
                int curr_sum = nums[front] + nums[back];
                if(abs(ans-target) > abs(curr_sum + a - target)){
                    ans = a + curr_sum;
                }
                if(curr_sum < (target-a)){
                    front++;
                }
                else if(curr_sum > (target-a)){
                    back--;
                }
                else{
                    return a + curr_sum;
                }
            }
        }
        return ans;
    }
};