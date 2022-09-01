class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            if((i>0) && nums[i] == nums[i-1]){continue;}
            long long a = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if((j>i+1) && nums[j] == nums[j-1]){continue;}
                long long b = nums[j];
                long long aim = target - a - b;
                int front = j+1; int back = nums.size() - 1;
                while(front < back){
                    long long sum = nums[front] + nums[back];
                    if(aim > sum){
                        front++;
                    }
                    else if(aim < sum){
                        back--;
                    }
                    else{
                        vector<int> temp = {(int)a,(int) b, nums[front], nums[back]};
                        ans.push_back(temp);
                        front++; back--;
                        while(front < back && temp[2] == nums[front])front++;
                        while(front < back && temp[3] == nums[back])back--;
                    }
                }
            }
        }
        return ans;
    }
};