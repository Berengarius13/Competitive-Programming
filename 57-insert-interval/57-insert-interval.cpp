class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        bool used = false; // If new interval is used or not
        if(intervals.size()==0 ||intervals[n-1][0] <= newInterval[0]){
            intervals.push_back(newInterval);
            used = true;
        }
        
        int prev_e = -1; int prev_s = -1;
        for(int i = 0; i < intervals.size(); i++){
            int curr_s = intervals[i][0];
            int curr_e = intervals[i][1];
            if(used == false && curr_s >= newInterval[0]){
                used = true; i--;
                curr_s = newInterval[0];
                curr_e = newInterval[1];
            }
            if(curr_s > prev_e){
                vector<int> temp {curr_s, curr_e};
                ans.push_back(temp);
                prev_s = curr_s; prev_e = curr_e;
            }
            else{
                if(curr_e >= prev_e){
                    ans[ans.size()-1][1] = curr_e;
                    prev_e = curr_e;
                }
            }
        }
        
        return ans;
    }
};