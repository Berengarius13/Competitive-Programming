class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0;
        int s1 = points[0][0]; 
        int e1 = points[0][1];
        for(int i = 1; i < points.size(); i++){
            int s2 = points[i][0];
            int e2 = points[i][1];
            
            if(s2 > e1){
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
        return points.size()-count;
    }
};