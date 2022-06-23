class Solution {
public:
    int maxArea(vector<int>& height) {
        map<int, int> mp;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i = 0; i < height.size(); i++){
            mp.insert({i, height[i]});
            pq.push(make_pair(height[i], i));
        }
        int max_area = INT_MIN;
        while(pq.size() != 1){
            int top = pq.top().first;
            int top_index = pq.top().second;
            pq.pop();
            mp.erase(top_index);
            auto begin = mp.begin();
            auto end = --mp.end();
            int max_index = begin->first;
            int min_index = end->first;
            int area = top * max(abs(top_index-max_index), abs(top_index-min_index));
            max_area = max(area, max_area);
        }
        return max_area;
    
    }
};