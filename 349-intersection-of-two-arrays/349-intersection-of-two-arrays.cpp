class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> mp1, mp2;
        set<int> ans;
        for(auto &num : nums1)
            mp1[num] = 1;
        for(auto &num : nums2)
            mp2[num] = 1;
        if(nums1.size()>nums2.size()){
            for(auto &num : nums1){
                if(mp1[num] == mp2[num])
                    ans.insert(num);
            }
        }
        else{
            for(auto &num : nums2){
                if(mp2[num] == mp1[num])
                    ans.insert(num);
            }
        }
        vector<int> real_ans;
        for(auto &it : ans)
            real_ans.push_back(it);
        return real_ans;
        
    }
};