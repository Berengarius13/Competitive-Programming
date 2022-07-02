class Solution {
public:
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first == p2.first)
            return p1.second > p2.second;
        else 
            return p1.first < p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &num : nums)
            mp[num]++;
        
        vector<pair<int,int>> vec;
        
        for(auto [number , frequency] : mp)
            vec.push_back(make_pair(frequency, number));
        
        sort(vec.begin(), vec.end(), comp);
        vector<int> ans;
        
        for(auto [frequency, number] : vec){
            for(int i = frequency; i > 0; i--){
                ans.push_back(number);
            }
        }
        return ans;
    }
};