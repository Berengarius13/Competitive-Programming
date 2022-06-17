class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> mst(n, 0);
        vector<int> dist(n, INT_MAX);
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            int node = pq.top().second; pq.pop();
            int x1 = points[node][0];
            int y1 = points[node][1];
            mst[node] =1;
            for(int i = 0; i < n; i++){
                int x2 = points[i][0];
                int y2 = points[i][1];
                int cost = (abs(x1 - x2) + abs(y1- y2));
                if(mst[i] == 0 && dist[i] > cost ){
                    dist[i] = cost;
                    pq.push({cost, i});
                }
            }
        }
        int sum = 0;
        for(auto &it : dist)
            sum+= it;
        return sum;
    }
};