/*
* Make map, and while insertion make cases
* map of start => end
*/
#define ll long long int
#define vll vector<long long>
#define pll pair<int, int> 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervalz) {
        vector<pll> intervals;
        for(auto &it : intervalz){
            intervals.push_back({it[0], it[1]});
        }
        sort(intervals.begin(), intervals.end());
        vector<pll> merged;
        pll prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            pll curr = intervals[i];
            if(curr.first > prev.second){
                merged.push_back(prev);
                prev = curr;
            }
            else{
                if(curr.second > prev.second){
                    prev.second = curr.second;
                }
            } 
        }
        merged.push_back(prev);
        vector<vector<int>> ans;
        for(auto &it : merged){
            vector<int> temp = {it.first, it.second};
            ans.push_back(temp);
                
        }
        return ans;
    }
    
};