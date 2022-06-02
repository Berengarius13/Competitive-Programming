class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++){
            int j = 0;
            int k = i;
            vector<int> temp;
            while(j < mat[0].size() && k < mat.size()){
                temp.push_back(mat[k][j]);
                j++;k++;
            }
            sort(temp.begin(), temp.end());
            j = 0;
            k = i;
            while(j < mat[0].size() && k < mat.size()){
                mat[k][j] = temp[j];
                j++;k++;
            }
        }
        for(int i = 0; i < mat[0].size(); i++){
            int j = 0;
            int k = i;
            vector<int> temp;
            while(j < mat.size() && k < mat[0].size()){
                temp.push_back(mat[j][k]);
                j++;k++;
            }
            j = 0;
            k = i;
            sort(temp.begin(), temp.end());
            while(j < mat.size() && k < mat[0].size()){
                mat[j][k] = temp[j];
                j++;k++;
            }
        }
        return mat;
    }
};