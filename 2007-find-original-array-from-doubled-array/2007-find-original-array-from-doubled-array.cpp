class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        if(changed.size()%2 != 0) return ans;
        unordered_map<int, int> mp;
        for(auto num : changed){
            mp[num]++;
        }
        sort(changed.begin(), changed.end());
        for(auto num : changed){
            if(mp[num] == 0) continue;
            mp[num]--;
            if(mp.find(num*2) != mp.end() && mp[num*2]>0){
                mp[num*2]--;
                ans.push_back(num);
            }
        }
        if(ans.size()*2 == changed.size()){
            return ans;
        }
        return vector<int> {};
    }
};