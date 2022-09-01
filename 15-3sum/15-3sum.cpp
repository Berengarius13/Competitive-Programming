class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &num : nums){
            mp[num]++;
        }
        set<vector<int>> unique;
        for(auto [a, a_count]: mp){
            mp[a]--;
            for(auto [b, b_count]: mp){
                if(mp[b] == 0) continue;
                mp[b]--;
                if(mp.find(-b-a) != mp.end() && mp[-b-a] > 0){
                    int c = -b-a;
                    vector<int> temp = {a, b, c};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                }
                mp[b]++;
            }
            mp[a]++;
        }
        vector<vector<int>> ans;
        for(auto &vec : unique){
            ans.push_back(vec);
        }
        return ans;
    }
};