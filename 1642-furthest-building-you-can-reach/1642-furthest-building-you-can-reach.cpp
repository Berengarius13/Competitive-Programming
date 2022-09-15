class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> climb(heights.size(), 0);
        for(int i = 1 ; i < heights.size(); i++){
            if(heights[i]- heights[i-1] >= 0)
                climb[i] = heights[i]-heights[i-1];
        }
        priority_queue<int> pq;
        int i = 0;
        for(i = 0; i < climb.size(); i++){
            int to_climb = climb[i];
            if(to_climb == 0) continue;
            if(to_climb <= bricks){
                bricks -= to_climb;
                pq.push(to_climb);
            }
            else if(ladders > 0){
                if(!pq.empty() && pq.top() >= to_climb){
                    bricks += pq.top();
                    pq.pop();
                    ladders--; // use the ladder
                    bricks -= to_climb;
                    pq.push(to_climb);
                }
                else{
                    ladders--;
                }
            }
            else{
                i+1; break;
            }
            
        }
        return i-1;
    }
};