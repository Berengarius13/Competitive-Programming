class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c) return mat;
        vector<vector<int>> ans (r, vector<int> (c));
        int i = 0; int j = 0;
        for(auto &it : mat){
            for(auto &num : it){
                if(j >= c){
                    j = 0; i++;
                }
                ans[i][j] = num;
                j++;
            }
        }
        return ans;
    }
};