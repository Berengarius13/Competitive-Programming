class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;
        for(auto &vec : boxTypes){
            pq.push(make_pair(vec[1], vec[0]));
        }
        int sum = 0;
        while(!pq.empty() && truckSize>0){
            int i = pq.top().second;
            while(i > 0 && truckSize > 0){
                sum += pq.top().first;
                truckSize--;
                i--;
            }
            pq.pop();
        }
        return sum;
    }
};