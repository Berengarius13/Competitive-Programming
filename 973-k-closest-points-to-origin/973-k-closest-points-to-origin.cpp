/*
* Max heap of frequency and point
*/
class Solution {
public:
    typedef pair<int, vector<int>> pv;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pv> pq;
        for(auto &point : points){
            int x = point[0];
            int y = point[1];
            pq.push(make_pair((x*x + y*y), point));
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};