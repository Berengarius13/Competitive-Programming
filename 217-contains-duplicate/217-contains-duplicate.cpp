class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(auto &num : nums){
            m[num]++;
        }
        for(auto &it : m){
            if(it.second > 1)
                return true;
        }
        return false;
    }
};