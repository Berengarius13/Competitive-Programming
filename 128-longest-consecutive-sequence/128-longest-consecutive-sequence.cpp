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
            // Mp = 2 means it is already counted as a consecutive sequence thus don't visit it
            if(pair.second == 1){
                int count = 1;
                int curr = pair.first;
                // Count all the consecutive elements and mark them as visited
                while(mp.find(curr-1) != mp.end()){
                    mp[--curr] = 2;
                    count++;
                }
                curr = pair.first;
                while(mp.find(curr+1) != mp.end()){
                    mp[++curr] = 2;
                    count++;
                }
                // In the end count the max count
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};