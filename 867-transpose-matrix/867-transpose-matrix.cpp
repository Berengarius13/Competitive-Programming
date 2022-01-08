class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // For Square Matrix
        // for(int i = 0; i< m; i++){
        //     for(int j =0; j<=i; j++){
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
        vector<vector<int>> ans(n, vector<int> (m,0));
        for(int i =0; i<n ;i++)
        {
            for(int j =0; j<m; j++)
                ans[i][j] = matrix[j][i];
        }
        
        return ans;
    }
};