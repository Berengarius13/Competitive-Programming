class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<vector<int>>> vec (2, vector<vector<int>> (n, vector<int> (n+1, 0)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    int k = matrix[i][j];
                    vec[0][i][k] = 1;
                    vec[1][j][k] = 1;
                }
            }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n+1; j++){
                if(vec[0][i][j] == 0 || vec[1][i][j] == 0)
                    return false;
            }
        }
        return true;
        }
        
    };