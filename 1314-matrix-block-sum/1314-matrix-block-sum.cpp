class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> prefix(matrix.size()+1, vector<int> (matrix[0].size()+1,0));
        for(int i = 1; i < matrix.size()+1; i++){
            for(int j = 1; j < matrix[0].size()+1; j++){
                prefix[i][j] = prefix[i][j-1] + matrix[i-1][j-1];
            }
        }
        for(int j = 1; j < matrix[0].size()+1; j++){
            for(int i = 1; i < matrix.size()+1; i++){
                prefix[i][j] += prefix[i-1][j];
             }
        }

        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> answer(n, vector<int> (m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int a = max(0, i - k);
                int b = max(0, j - k);
                int x = min(n-1, i + k);
                int y = min(m-1, j + k);
                answer[i][j] = prefix[x+1][y+1] - prefix[a][y+1] - prefix[x+1][b] + prefix[a][b];
            }
        }
        return answer;
    }
};