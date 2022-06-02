class Solution {
public:
    vector<int> ans;
    bool dfs(vector<vector<int>>& matrix, int i, int j){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return true;
        if(matrix[i][j] == -300) return true; // AKA visited
        ans.push_back(matrix[i][j]);
        matrix[i][j] = -300;
        dfs(matrix, i, j+1);
        dfs(matrix, i+1, j);
        bool a = dfs(matrix, i, j-1);
        if(a){
            while(i-1 >= 0 && matrix[i-1][j] != -300){
                ans.push_back(matrix[i-1][j]); matrix[i-1][j] = -300;
                i--;
            }
            dfs(matrix, i, j+1);
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;
    // {
    //     while(j < matrix[0].size() && matrix[i][j] != -300){
    //         ans.push_back(matrix[i][j]); matrix[i][j] == -300;
    //         j++;
    //     }
    //     j--;
    //     while(i < matrix.size() && matrix[i][j] != -300){
    //         ans.push_back(matrix[i][j]); matrix[i][j] == -300;
    //         i++;
    //     }
    //     i--;
    //     while(j >= 0 && matrix[i][j] != -300){
    //         ans.push_back(matrix[i][j]); matrix[i][j] == -300;
    //         j--;
    //     }
    //     j++;
    //     while(i >= 0 && matrix[i][j] != -300){
    //         ans.push_back(matrix[i][j]); matrix[i][j] == -300;
    //         i--;
    //     }
    //     i++;
    // }    
        dfs(matrix, i, j);
        return ans;
    }
};