class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0; int j = 0;
        while(i < firstList.size() && j < secondList.size()){
            int s1, s2, e1, e2;
            s1 = firstList[i][0]; e1 = firstList[i][1];
            s2 = secondList[j][0]; e2 = secondList[j][1];
            
            if(s2 >= s1){
                if(s2 > e1){
                    i++;
                    continue;
                }
                if(e2 == e1){
                    ans.push_back(vector<int> {s2, e2});
                    i++; j++;
                }
                else if ( e2 > e1){
                    ans.push_back(vector<int> {s2, e1});
                    secondList[j][0] = e1 + 1;
                    i++;
                }
                else{
                    ans.push_back(vector<int> {s2, e2});
                    firstList[i][0] = e2+1;
                    j++;
                }
            }
            else{
                if(s1 > e2){
                    j++;
                    continue;
                }
                if(e2 == e1){
                    ans.push_back(vector<int> {s1, e1});
                    i++; j++;
                }
                else if ( e1 > e2){
                    ans.push_back(vector<int> {s1, e2});
                    firstList[i][0] = e2 + 1;
                    j++;
                }
                else{
                    ans.push_back(vector<int> {s1, e1});
                    secondList[j][0] = e1+1;
                    i++;
                }
            }
        }
        return ans;
    }
};