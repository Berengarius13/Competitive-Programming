class Solution {
public:
    int trap(vector<int>& nums) {
        multimap<int, int, greater<int>> mp; // peak => index
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 && i + 1 < n && nums[i] > nums[i+1]){
                mp.insert({nums[i], i});
            }
            else if(i == nums.size()-1 && i-1 >= 0 && nums[i] > nums[i-1]){
                mp.insert({nums[i], i});
            }
            else{
                if(i + 1 < n && i - 1 >= 0 && (nums[i] > nums[i-1] && nums[i] > nums[i+1] || nums[i] >= nums[i-1] && nums[i] > nums[i+1] || nums[i] >= nums[i+1] && nums[i] > nums[i-1]) ){
                    mp.insert({nums[i], i});
                }
            }
        }
        int l = -1;
        int r = -1;
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it == mp.begin()){
                l = it->second;
                r = it->second;
            }
            else{
                int id = it->second;
                int peak = it->first;
                if(id > r){
                    for(int i = r+1; i < id; i++){
                        if(peak - nums[i] > 0) ans += peak - nums[i];
                    }
                    r = id;
                }
                else if(id < l){
                    for(int i = id+1; i < l; i++){
                        if(peak - nums[i] > 0) ans += peak - nums[i];
                    }
                    l = id;
                }
            }
        }
        return ans;
    }
};