/*
* Min heap of k size
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        unordered_map<int,int> mp;
        for(auto &num : nums)
            mp[num]++;
        
        for(auto [num , frequency] : mp){
            pq.push(make_pair(frequency, num));
            if(pq.size() > k) 
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};