class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), comp);
        int s1 = intervals[0][0]; 
        int e1 = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            
            if(s2 >= e1){
                s1 = s2; 
                e1 = e2; continue;
            }
            if(e2 >= e1){
                count++;
            }
            else{
                count++;
                s1 = s2;
                e1 = e2;
            }
        }
        return count;
    }
};