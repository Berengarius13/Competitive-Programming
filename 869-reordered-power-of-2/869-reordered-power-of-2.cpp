class Solution {
public:
    bool ans = false;
    void dfs(string &nums, int begin){
        if(begin == nums.size()-1){
            if(nums[0] == '0') return;
            int temp = stoi(nums);
            if((temp & (temp-1))==0) ans = true;
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            swap(nums[i], nums[begin]);
            dfs(nums, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
    bool permute(string& nums) {
        dfs(nums, 0);
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        permute(str);
        return ans;
    }
};