/*
* Formula is l*h or (j-i) * min(h[i], h[j])
* Pick up the best bet, the boundaries of container as then
  we will have maximum length
* How to proceed then? reduce lenght by one and discard the shorter
  wall and pick the wall next to it
* We don't need to check all cases of len-1 because we are discarding
  shorter wall hence it will be definatly shorter
when ai < aj, if we move j to the left:
1. the length on x-axis will definitly decrease
2. if a(j-1) > ai, the area will be ai * length on x-axis which is smaller than original area
3. if a(j-1) < ai, the area will be a(j-1) * length on x-axis which is also smaller than original area
so moving j to the left won't give us a larger area, we can only move i to the right to get a possible larger area.
// Proof by contradiction
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int i = 0; int j = height.size()-1;
        while(i < j){
            int area = (j-i)*min(height[i], height[j]);
            max_area = max(max_area, area);
            if(height[i] > height[j])
                j--;
            else 
                i++;
        }
        return max_area;
    }
};















































/*
// O(NlogN) solution using priority queue and map
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
*/