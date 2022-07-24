class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j = matrix[0].size()-1;
        int i = 0;
        int m = matrix.size(); int n = matrix[0].size();
        while(i < m && j  >= 0){
            if(target == matrix[i][j]) return true;
            else if(target < matrix[i][j]){
                j--;
            }
            else{
                i++;
            }
                
        }
        return false;
    }
};