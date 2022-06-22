class Solution {
public:
    bool dfs(vector<vector<int>> &matrix, int i, int j, int counter){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return true;
        if(matrix[i][j] != 0) return true;
        
        matrix[i][j] = counter;
        dfs(matrix, i, j+1, counter+1);
        dfs(matrix, i+1, j, counter+1);
        bool a = dfs(matrix, i, j-1, counter+1);
        if(a){
            while(i-1 >= 0 && matrix[i-1][j] == 0){
                counter++;
                matrix[i-1][j] = counter;
                i--;
            }
           dfs(matrix, i, j+1, counter+1);
        }
        return false;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        dfs(matrix, 0, 0, 1);
        return matrix;
    }
};