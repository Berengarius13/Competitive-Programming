class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = 0; int end = 0;
        for(auto &pair : intervals){
            if(mp.empty()){
                mp.insert({pair[0], pair[1]});
                start = pair[0]; end = pair[1];
            }
            else{
                int startb = pair[0]; int endb = pair[1];
                if(startb <= end){
                    if(endb >= end){
                        mp[start] = endb;
                        start = start; end = endb;
                    }
                }
                else{
                    mp.insert({startb, endb});
                    start = startb; end = endb;
                }
            }
        }
        for(auto &m : mp){
            vector<int> temp {m.first, m.second};
            ans.push_back(temp);
        }
        return ans;
    }
};