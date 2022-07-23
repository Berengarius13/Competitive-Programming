class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> mp1, mp2;
        unordered_set<int> s;
        vector<int> ans;
        for(auto &num : nums1){
            mp1[num]++;
            s.insert(num);
        }
        for(auto &num : nums2){
            mp2[num]++;
             s.insert(num);
        }
        for(auto &num : s){
            int count = min(mp1[num], mp2[num]);
            while(count){
                ans.push_back(num);
                count--;
            }
        }
       return ans;
    }
};