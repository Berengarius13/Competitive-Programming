
class Solution {
public:
    class comp{
        public:
        bool operator()(pair<int, string> &p1, pair<int, string> &p2){
            if(p1.first == p2.first){
                int i = 0; int j = 0;
                while(i < p1.second.size() && j < p2.second.size()){
                    if(p1.second[i] != p2.second[j])
                        return p1.second[i] < p2.second[j];
                    i++; j++;
                }
                return p1.second.size() < p2.second.size();
            }
            return p1.first > p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto &word : words)
            mp[word]++;
       
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto [word, frequency] : mp){
            pq.push(make_pair(frequency, word));
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};