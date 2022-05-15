class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto &st: strs){
            string temp = st;
            sort(temp.begin(), temp.end());
            m[temp].push_back(st);
        }
        vector<vector<string>> ans;
        for(auto &ma: m){
            ans.push_back(ma.second);
        }
        return ans;
    }
};