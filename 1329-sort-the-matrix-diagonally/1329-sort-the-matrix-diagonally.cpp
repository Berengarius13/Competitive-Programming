class Solution {
public:
    void sort_diagnol(vector<vector<int>> &matrix, int i, int j){
        vector<int> arr;
        int temp_i = i; int temp_j = j;
        while(i < matrix.size() && j < matrix[0].size()){
            arr.push_back(matrix[i][j]);
            i++; j++;
        }
        sort(arr.begin(), arr.end());
        i = temp_i; j = temp_j;
        int k = 0;
        while(i < matrix.size() && j < matrix[0].size()){
            matrix[i][j] = arr[k];
            k++; i++; j++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++){
            sort_diagnol(mat, i, 0);
        }
        for(int j = 1; j < mat[0].size(); j++){
            sort_diagnol(mat, 0, j);
        }
        return mat;
    }
};