class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        // Make map of (num = > 1), 1 remembers that it is filled, but not visited yet
        for(auto &num : nums)
            mp.insert({num, 1});
        int max_count = 0;
        // Iterate over map
        for(auto &pair : mp){
            if(pair.second == 1){
                int count = 1;
                int curr = pair.first;
                while(mp.find(curr-1) != mp.end()){
                    mp[--curr] = 2;
                    count++;
                }
                curr = pair.first;
                while(mp.find(curr+1) != mp.end()){
                    mp[++curr] = 2;
                    count++;
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};